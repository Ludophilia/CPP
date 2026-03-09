/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 20:16:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/09 13:43:19 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const String &name, Weapon &weapon):
	_weapon(weapon), _name(name)
{
	std::cout << "HumanA " << this->_name << " created" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA " << this->_name << " destroyed" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name 
			  << " attacks with their "
			  << (this->_weapon).getType()
			  << std::endl;
}
