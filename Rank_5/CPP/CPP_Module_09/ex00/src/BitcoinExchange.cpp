/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:29:21 by yfang             #+#    #+#             */
/*   Updated: 2025/03/26 18:55:06 by yfang            ###   ########.fr       */
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

        if (date.empty() || !ss) {
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
