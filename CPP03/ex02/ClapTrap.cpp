/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:29:10 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/20 21:55:18 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("???"), _hitPts(10),
	_energyPts(10), _attackDmg(0)
{
	cout << "ClapTrap default constructor called (" << this << ")" << endl;
}

ClapTrap::ClapTrap(const string &name): _name(name), _hitPts(10),
	_energyPts(10), _attackDmg(0)
{
	cout << "ClapTrap string constructor called (" << this << ")" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &src): _name(src._name), _hitPts(src._hitPts),
	_energyPts(src._energyPts), _attackDmg(src._attackDmg)
{
	cout << "ClapTrap copy constructor called (" << this << ")" << endl;
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap default destructor called (" << this << ")" << endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPts = rhs._hitPts;
		_energyPts = rhs._energyPts;
		_attackDmg = rhs._attackDmg;
	}
	return (*this);
}

void	ClapTrap::attack(const string &target)
{
	if (_hitPts <= 0 || _energyPts <= 0)
		cout << "ClapTrap " << _name << " cannot attack!" << endl;
	else
	{
		_energyPts -= 1;
		cout << "ClapTrap " << _name << " attacks " << target
			 << ", causing " << _attackDmg << " points of damage!"
			 << endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitPts -= amount;
	cout << "ClapTrap " << _name << " takes " << amount << " points of damage!"
		 << endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPts <= 0 || _hitPts <= 0)
		cout << "ClapTrap " << _name << " cannot repair itself!\n";
	else
	{
		_energyPts -= 1;
		_hitPts =+ amount;
		cout << "ClapTrap " << _name << " repairs itself"
			 << ", recovering " << amount << " hit points!"
			 << endl;
	}
}
