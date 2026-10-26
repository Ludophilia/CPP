/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:21:46 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/26 23:40:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() // ClapTrap(), FragTrap(), ScavTrap() // <== Not needed ???
{
	cout << endl;

	_name = "???";
	ClapTrap::_name = _name + "_clap_name";
	// _hitPts = FragTrap::_hitPts;
	// _energyPts = ScavTrap::_energyPts;
	// _attackDmg = FragTrap::_attackDmg;
	

	// WHAT THE F*?
	// Eeach initializer is writing the same memory addresses.
	// ScavTrap is the last one to write in the same three spots, hence 
	// why those results match ScavTrap default values...
	
	cout
		 << "FragTrap::_hitPts: " << FragTrap::_hitPts << '\n'
	     << "ScavTrap::_hitPts: " << ScavTrap::_hitPts << '\n'
	     << "ClapTrap::_hitPts: " << ClapTrap::_hitPts << '\n'
		 << '\n'
		 << "FragTrap::_energyPts: " << FragTrap::_energyPts << '\n'
		 << "ScavTrap::_energyPts: " << ScavTrap::_energyPts << '\n'
		 << "ClapTrap::_energyPts: " << ClapTrap::_energyPts << '\n'
		 << '\n'
		 << "FragTrap::_attackDmg: " << FragTrap::_attackDmg << '\n'
		 << "ScavTrap::_attackDmg: " << ScavTrap::_attackDmg << '\n'
		 << "ClapTrap::_attackDmg: " << ClapTrap::_attackDmg << '\n'
		 << endl;

	cout << endl;

	cout << "name: " << _name << '\n'
		 << "clap name: " << ClapTrap::_name << '\n'
		 << "hit points: " << _hitPts << '\n'
		 << "energy points: " << _energyPts << '\n'
		 << "attack damage: " << _attackDmg << '\n'
		 << endl;

	cout << "DiamondTrap default constructor called (" << this << ")" << endl;
}


// DiamondTrap::DiamondTrap()
// {
// 	_name = "???";
// 	ClapTrap::_name = _name + "_clap_name";
// 	_hitPts = _hitPts;
// 	_energyPts = _energyPts;
// 	_attackDmg = _attackDmg;


// 	cout << "name: " << diamond._name
// 		 << "clap name: " << diamond.ClapTrap::_name


// 		 << endl;


// 	cout << "DiamondTrap default constructor called (" << this << ")" << endl;


// }


// DiamondTrap::DiamondTrap(): ClapTrap("James")
// {
// 	cout << "DiamondTrap default constructor called (" << this << ")" << endl;
// }

DiamondTrap::~DiamondTrap()
{
	cout << "DiamondTrap default destructor called (" << this << ")" << endl;
}
