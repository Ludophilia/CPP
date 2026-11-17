/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:21:46 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/28 16:38:49 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// ClapTrap, ScavTrap, FragTrap default constructors are implicitely added 
// and called here before DiamondTrap construction and _name initialization.
DiamondTrap::DiamondTrap(): _name("default")
{
	ClapTrap::_name = _name + "_clap_name";
	_hitPts = FragTrap::_HP_DFLT;
	_energyPts = ScavTrap::_EP_DFLT;
	_attackDmg = FragTrap::_AD_DFLT;
	cout << "DiamondTrap default constructor called (" << this << ")" << endl;
}

// For non-default constructors however, they need to be explicitely called
// in the member initializer list, in the same order as what's been written in
// the class declaration.
DiamondTrap::DiamondTrap(const string &name): ClapTrap(name + "_clap_name"),
	FragTrap(), ScavTrap(), _name(name)
{
	_hitPts = FragTrap::_HP_DFLT;
	_energyPts = ScavTrap::_EP_DFLT;
	_attackDmg = FragTrap::_AD_DFLT;
	cout << "DiamondTrap string constructor called (" << this << ")" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), FragTrap(src),
	ScavTrap(src), _name(src._name)
{
	cout << "DiamondTrap copy constructor called (" << this << ")" << endl;
}

DiamondTrap::~DiamondTrap()
{
	cout << "DiamondTrap default destructor called (" << this << ")" << endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (&rhs != this)
	{
		_name = rhs._name;
		ClapTrap::_name = rhs.ClapTrap::_name;
	 	_hitPts = rhs._hitPts;
		_energyPts = rhs._energyPts;
		_attackDmg = rhs._attackDmg;
	}
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	cout << "I'm " << _name << ", also known as "
		 << ClapTrap::_name << ", nice to meet you!"
		 << endl;
}

// cout << "name: " << _name << '\n'
//  << "clap name: " << ClapTrap::_name << '\n'
//  << "hit points: " << _hitPts << '\n'
//  << "energy points: " << _energyPts << '\n'
//  << "attack damage: " << _attackDmg << '\n'
//  << endl;