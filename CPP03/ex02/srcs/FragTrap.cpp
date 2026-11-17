/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:05:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/21 22:01:37 by jegerman         ###   ########.fr       */
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

// That implementation is unnecessary. In order to respect the rule of 
// three / canonical form however, I will keep it as is.
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

void	FragTrap::highFivesGuys()
{
	cout << "FragTrap " << _name << " wants to high five!!!"
		 << endl;
}
