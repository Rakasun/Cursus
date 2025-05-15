/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:29:21 by yfang             #+#    #+#             */
/*   Updated: 2025/05/15 18:19:22 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _btcRates(other._btcRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        _btcRates = other._btcRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

void    BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    
    std::string line;
    std::string date;
    float       rate;
    while (getline(file, line)) {
        std::stringstream   ss(line);
        if (getline(ss, date, ',') && ss >> rate)
            _btcRates[date] = rate;
    }
    file.close();
}

float   BitcoinExchange::getExchangeRate(const std::string &date) {
    std::map<std::string, float>::const_iterator it = _btcRates.lower_bound(date);

    if (it != _btcRates.begin() && (it == _btcRates.end() || it->first != date))
        --it;
    if (it == _btcRates.end()) {
        std::cerr << "Error: date not found in database." << std::endl;
        return -1;
    }
    return it->second;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool checkDate(std::string &date) {
    if (date.empty() || date.length() != 11 || date[4] != '-' || date[7] != '-' || date[10] != ' ')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (size_t i = 0; i < 4; ++i)
        if (!isdigit(yearStr[i]))
            return false;
    
    for (size_t i = 0; i < 2; ++i)
        if (!isdigit(monthStr[i]) || !isdigit(dayStr[i]))
            return false;

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (month < 1 || month > 12)
        return false;
    
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;
    
    return true;
}

void    BitcoinExchange::processInputFile(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    
    std::string line;
    std::string date;
    float       value;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);

        std::getline(ss, date, '|');
        ss >> value;

        if (!checkDate(date) || !ss) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = getExchangeRate(date);
        if (rate != -1)
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
    file.close();
}
