/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:39:53 by yfang             #+#    #+#             */
/*   Updated: 2024/08/20 15:57:12 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() {
    std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << now->tm_mon + 1
              << std::setw(2) << std::setfill('0') << now->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec
              << "]";
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
    _nbAccounts--;
    _totalAmount -= _amount;
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << " accounts: " << getNbAccounts()
        << ";total:" << getTotalAmount()
        << ";deposits:" << getNbDeposits()
        << ";withdrawals" << getNbWithdrawals()
        << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
    if (_amount < withdrawal) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount() const {
    return _amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits 
              << ";withdrawals:" << _nbWithdrawals 
              << std::endl;
}
