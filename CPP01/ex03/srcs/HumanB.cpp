/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:44:22 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/11 21:48:28 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const string &name): _weapon(NULL), _name(name) {}

void	HumanB::attack() const
{
	if (_weapon)
		cout << _name << " attacks with their " << _weapon->getType();
	else
		cout << _name << " can't attack without a weapon!";
	cout << endl;
}

void	HumanB::setWeapon(const Weapon &weapon)
{
	_weapon = &weapon;
}
