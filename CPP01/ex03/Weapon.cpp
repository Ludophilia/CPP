/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:07:03 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/09 13:57:52 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

int	Weapon::count = 0;

String	&Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(String newType)
{
	this->_type = newType;
}

// Weapon::Weapon(void)
// {
// 	Weapon::count++;
// 	std::cout << "Weapon "
// 			  << Weapon::count
// 			  << " created" << std::endl;
// }

// Weapon::~Weapon(void)
// {
// 	std::cout << "Weapon "
// 			  << Weapon::count
// 			  << " destroyed" << std::endl;
// 	Weapon::count--;
// }

Weapon::Weapon(const String &type)
{
	Weapon::count++;
	std::cout << "Weapon "
			  << Weapon::count
			  << " created from string ref" << std::endl;
	this->_type = type;
}
