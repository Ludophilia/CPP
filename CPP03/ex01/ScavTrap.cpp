/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:05:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/18 01:30:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
 	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const String &name): ClapTrap(name)
{
	this->_name = name;
 	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 20;
	std::cout << "String ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap()
{
	(*this) = src;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
	 	this->_hit_pts = rhs._hit_pts;
		this->_energy_pts = rhs._energy_pts;
		this->_attack_dmg = rhs._attack_dmg;
	}
	return (*this);
}

void	ScavTrap::attack(const String &target)
{
	if (this->_energy_pts <= 0 || this->_hit_pts <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack!\n";
		return ;
	}
	this->_energy_pts -= 1;
	std::cout << "ScavTrap " << this->_name
			  << " attacks " << target
			  << ", causing " << this->_attack_dmg
			  << " points of damage!"
			  << std::endl;
	// target.takeDamage(this->_attack_dmg);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;

}
ScavTrap::~ScavTrap(void)
{
	std::cout << "Default ScavTrap destructor called" << std::endl;
}
