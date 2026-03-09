/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:07:03 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/09 14:22:54 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const String	&Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(String newType)
{
	this->_type = newType;
}

Weapon::Weapon(const String &type)
{
	this->_type = type;
}
