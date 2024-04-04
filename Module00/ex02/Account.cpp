/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:28:11 by tmarts            #+#    #+#             */
/*   Updated: 2024/04/03 19:24:55 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	
	_accountIndex = _nbAccounts;
	++_nbAccounts;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created" << "\n";
}

Account::~Account() {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed" << "\n";
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	std::cout << ";amount:" << _amount
			<<";nb_deposits:" << _nbDeposits << "\n";	
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << "\n";
		return 1;
	}
	std::cout << withdrawal;
	_amount -= withdrawal;
	_nbWithdrawals++;
	std::cout << ";amount:" << _amount
			<<";nb_withdrawals:" << _nbWithdrawals << "\n";	
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return 0;
}

int		Account::checkAmount() const {
	return _amount;
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << "\n";		
}

void	Account::_displayTimestamp() {
	std::time_t now = std::time(NULL);
	struct tm *tm_info = localtime(&now);
	char timeStamp[18];
	std::strftime(timeStamp, 18, "[%Y%m%d_%H%M%S]", tm_info);
	std::cout << timeStamp;
	// std::cout << "[19920104_091532]"; //to get an identical result for diff
}

//getters and "printers"
int	Account::getNbAccounts() {
	return _nbAccounts;
}

int	Account::getTotalAmount() {
	return _totalAmount;
}

int	Account::getNbDeposits() {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << "\n";		
}