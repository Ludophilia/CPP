/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:05:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/20 23:51:17 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_hitPts = 100;
	_energyPts = 100;
	_attackDmg = 30;
	cout << "FragTrap default constructor called (" << this << ")" << endl;
}

FragTrap::FragTrap(const string &name): ClapTrap(name)
{
	_hitPts = 100;
	_energyPts = 100;
	_attackDmg = 30;
	cout << "FragTrap string constructor called (" << this << ")" << endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
	cout << "FragTrap copy constructor called (" << this << ")" << endl;
}

FragTrap::~FragTrap()
{
	cout << "FragTrap default destructor called (" << this << ")" << endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
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

void	FragTrap::attack(const string &target)
{
	if (_energyPts <= 0 || _hitPts <= 0)
		cout << "FragTrap " << _name << " cannot attack!" << endl;
	else
	{
		_energyPts -= 1;
		cout << "FragTrap " << _name << " attacks " << target
			 << ", causing " << _attackDmg << " points of damage!"
			 << endl;
	}
}

void	FragTrap::highFivesGuys()
{
	cout << "FragTrap " << _name << " wants to high five!!!"
		 << endl;
}
