/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:05:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/18 21:21:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
 	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_dmg = 30;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const String &name): ClapTrap(name)
{
	this->_name = name;
 	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_dmg = 30;
	std::cout << "String FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap()
{
	(*this) = src;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
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

void	FragTrap::attack(const String &target)
{
	if (this->_energy_pts <= 0 || this->_hit_pts <= 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot attack!\n";
		return ;
	}
	this->_energy_pts -= 1;
	std::cout << "FragTrap " << this->_name
			  << " attacks " << target
			  << ", causing " << this->_attack_dmg
			  << " points of damage!"
			  << std::endl;
	// target.takeDamage(this->_attack_dmg);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " wants to high five!!!"
			  << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Default FragTrap destructor called" << std::endl;
}
