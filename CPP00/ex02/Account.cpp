/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:22:52 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/14 19:57:01 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Account.hpp>

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

// static void	_displayTimestamp( void ); // private
	// [19920104_091532]

// static void	displayAccountsInfos( void );
	//	[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
		// 	static int	_nbAccounts; (accounts:8)
		// 	static int	_totalAmount; (total:20049)
		// 	static int	_totalNbDeposits; (deposits:0)
		// static int	_totalNbWithdrawals; (withdrawals:0)
		// Maybe use the getters?

// Account( void ); // private
// Account( int initial_deposit );
	// [19920104_091532] index:0;amount:42;created
		// created suggest an initializer
			// maybe using Account( void ); // private
				// (index:0;)_accountIndex is derived from _nbAccounts
				// _nbDeposits = 0
				// _nbWithdrawals = 0
				// _amount = 0;
		// amount:42 is (int initial_deposit) (_amount)
	
// ~Account( void );
	// [19920104_091532] index:0;amount:47;closed
	// 	int				_accountIndex; (index:0)
	// int				_amount; (amount:47)

// void	displayStatus( void ) const;
	// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
		// int				_accountIndex;
		// int				_amount;
		// int				_nbDeposits;
		// int				_nbWithdrawals;


// void	makeDeposit( int deposit );
	// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
		// p_amount for previous amount (_amount)
		// _amount (after add)
		// _nbDeposits += 1
		// _totalNbDeposits += 1

// bool	makeWithdrawal( int withdrawal );
	// [19920104_091532] index:0;p_amount:47;withdrawal:refused
	// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
		// if witdrawal > _amount, refused
		// p_amount for previous amount (_amount)
		// _amount (after add)
		// _nbWithdrawals += 1
		// _totalNbWithdrawals += 1

// void	displayStatus( void ) const;

// int		checkAmount( void ) const;
	// Looks like a getter to _amount: no parametters, don't mod the instance
	// 	int				_amount;
	// it's not a test, as it's not bool
