/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:07:03 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 18:50:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const string	&Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(string newType)
{
	this->_type = newType;
}

Weapon::Weapon(const string &type)
{
	this->_type = type;
}
