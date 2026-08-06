/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:22:52 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/06 22:27:18 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <iomanip>
#include <Account.hpp>

int	Account::_nbAccounts = 0;

int	Account::_totalAmount = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
	const time_t		now = std::time(NULL);
	const struct tm		* const tm = std::localtime(&now);

	std::cout << '[' << std::setfill('0')
			  << std::setw(4) << tm->tm_year + 1900
			  << std::setw(2) << tm->tm_mon + 1
			  << std::setw(2) << tm->tm_mday
			  << '_'
			  << std::setw(2) << tm->tm_hour
			  << std::setw(2) << tm->tm_min
			  << std::setw(2) << tm->tm_sec
			  << ']' << ' ';
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
			  << "total:" << Account::getTotalAmount() << ";"
			  << "deposits:" << Account::getNbDeposits() << ";"
			  << "withdrawals:" << Account::getNbWithdrawals()
			  << std::endl;
}

void	Account::_initAccount(int initial_deposit)
{
	_accountIndex = Account::_nbAccounts;
	_amount = initial_deposit;
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	Account::_nbAccounts++;
	if (initial_deposit > 0)
		Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "created"
			  << std::endl;
}

Account::Account(void)
{
	_initAccount(0);
}

// [19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit)
{
	_initAccount(initial_deposit);
}

// [19920104_091532] index:0;amount:47;closed
Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "closed"
			  << std::endl;
	Account::_nbAccounts--;
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals
			  << std::endl;
}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit(int deposit)
{
	const int	p_amount = checkAmount();

	_amount += deposit;
	_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << checkAmount() << ";"
			  << "nb_deposits:" << _nbDeposits
			  << std::endl;
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal(int withdrawal)
{
	const int	p_amount = checkAmount();

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "withdrawal:";
	if (withdrawal > p_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << ";"
			  << "amount:" << checkAmount() << ";"
			  << "nb_withdrawals:" << _nbWithdrawals
			  << std::endl;
	return (true);
}
