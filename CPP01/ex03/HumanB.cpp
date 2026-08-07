/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:44:22 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 18:50:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const string &name): _name(name)
{
	this->_weapon = NULL;
}

void	HumanB::attack(void)
{
	std::cout << this->_name;
	if (this->_weapon == NULL)
		std::cout << " can't attack without a weapon!";
	else
		std::cout << " attacks with their " << (this->_weapon)->getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
