/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:29:10 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/18 01:50:57 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("???"), _hit_pts(10), _energy_pts(10),
	_attack_dmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const String &name): _name(name), _hit_pts(10),
	_energy_pts(10), _attack_dmg(0)
{
	std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src): _name(src._name), 
	_hit_pts(src._hit_pts), _energy_pts(src._energy_pts),
	_attack_dmg(src._attack_dmg)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Default destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
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

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_pts <= 0 || this->_hit_pts <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack!\n";
		return ;
	}
	this->_energy_pts -= 1;
	std::cout << "ClapTrap " << this->_name
			  << " attacks " << target
			  << ", causing " << this->_attack_dmg
			  << " points of damage!"
			  << std::endl;
	// target.takeDamage(this->_attack_dmg);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_pts -= amount;
	std::cout << "ClapTrap " << this->_name
			  << " takes " << amount
			  << " points of damage!"
			  << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_pts <= 0 || this->_hit_pts <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot repair itself!\n";
		return ;
	}
	this->_energy_pts -= 1;
	this->_hit_pts =+ amount;
	std::cout << "ClapTrap " << this->_name
			  << " repairs itself"
			  << ", recovering " << amount
			  << " hit points!"
			  << std::endl;
}
