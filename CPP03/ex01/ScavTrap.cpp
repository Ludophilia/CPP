/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:05:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/16 23:12:40 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
 	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
	cout << "Default ScavTrap constructor called" << endl;
}

ScavTrap::ScavTrap(const string &name): ClapTrap(name)
{
	_name = name;
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
	cout << "String ScavTrap constructor called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap()
{
	(*this) = src;
	cout << "ScavTrap copy constructor called" << endl;
}

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
		cout << "ScavTrap " << _name << " cannot attack!\n";
	else
	{
		_energyPts -= 1;
		// target.takeDamage(_attackDmg);
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

ScavTrap::~ScavTrap()
{
	cout << "Default ScavTrap destructor called" << endl;
}
