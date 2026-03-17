/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:05:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/17 02:04:09 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) // :ClapTrap
{
	std::cout << "Default ScavTrap constructor called" << std::endl;

	std::cout << "_name: " << this->_name << "\n";
	std::cout << "_hit_pts: " << this->_hit_pts << "\n";
	std::cout << "_energy_pts: " << this->_energy_pts << "\n";
	std::cout << "_attack_dmg: " << this->_attack_dmg << "\n";

	this->_name = "base";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Default ScavTrap destructor called" << std::endl;
	
}
