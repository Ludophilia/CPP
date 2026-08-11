/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:07:03 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/11 18:53:42 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const string &type): _type(type) {}

const string	&Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(const string &newType)
{
	_type = newType;
}
