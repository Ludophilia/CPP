/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:22:52 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/03 16:22:23 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Account.hpp>
#include <ctime>
#include <cstdio>
#include <iostream>

int	Account::_nbAccounts = 0;

int	Account::_totalAmount = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (t::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (t::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (t::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (t::_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
	time_t		now;
	struct tm	*tm;
	char		ts[32];

	now = std::time(NULL);
	tm = std::localtime(&now);
	std::sprintf(ts, "[%4i%02i%02i_%02i%02i%02i]",
					tm->tm_year + 1900,
					tm->tm_mon + 1,
					tm->tm_mday,
					tm->tm_hour,
					tm->tm_min,
					tm->tm_sec);
	std::cout << ts << " ";
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
			  << "total:" << Account::getTotalAmount() << ";"
			  << "deposits:" << Account::getNbDeposits() << ";"
			  << "withdrawals:" << Account::getNbWithdrawals() << ";"
			  << std::endl;
}

void	Account::_initAccount(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	if (initial_deposit)
		Account::_totalAmount += initial_deposit;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	Account::_nbAccounts += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->checkAmount() << ";"
			  << "created"
			  << std::endl;
}

Account::Account(void)
{
	this->_initAccount(0);
}

// [19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit)
{
	this->_initAccount(initial_deposit);
}

// [19920104_091532] index:0;amount:47;closed
Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->checkAmount() << ";"
			  << "closed"
			  << std::endl;
	Account::_nbAccounts--;
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->checkAmount() << ";"
			  << "deposits:" << this->_nbDeposits << ";"
			  << "withdrawals:" << this->_nbWithdrawals << ";"
			  << std::endl;
}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = this->checkAmount();
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << this->checkAmount() << ";"
			  << "nb_deposits:" << this->_nbDeposits << ";"
			  << std::endl;
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = this->checkAmount();
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "withdrawal:";
	if (withdrawal > p_amount)
		return (std::cout << "refused\n", false);
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout << withdrawal << ";"
			  << "amount:" << this->checkAmount() << ";"
			  << "nb_withdrawals:" << this->_nbWithdrawals
			  << std::endl;
	return (true);
}
