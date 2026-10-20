/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:05:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/20 21:55:08 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// ClapTrap default constructor is implicitely added and called here.
ScavTrap::ScavTrap()
{
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
	cout << "ScavTrap default constructor called (" << this << ")" << endl;
}

// For non-default constructors however, they need to be explicitely called
// in the member initializer list.
ScavTrap::ScavTrap(const string &name): ClapTrap(name)
{
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
	cout << "ScavTrap string constructor called (" << this << ")" << endl;
}

// Surprisingly enough, calling the ClapTrap copy constructor on a ScavTrap
// instance DOES work.
ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
	cout << "ScavTrap copy constructor called (" << this << ")" << endl;
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap default destructor called (" << this << ")" << endl;
}

// Following on that realization about the copy constructor, turns out
// that implementation is also unnecessary. In order to respect the rule of 
// three / canonical form however, I will keep it as is.
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
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

void	ScavTrap::attack(const string &target)
{
	if (_energyPts <= 0 || _hitPts <= 0)
		cout << "ScavTrap " << _name << " cannot attack!" << endl;
	else
	{
		_energyPts -= 1;
		cout << "ScavTrap " << _name << " attacks " << target
			 << ", causing " << _attackDmg << " points of damage!"
			 << endl;
	}
}

void	ScavTrap::guardGate()
{
	cout << "ScavTrap " << _name << " is now in Gatekeeper mode."
		 << endl;
}
