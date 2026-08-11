/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 20:16:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/11 21:45:52 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const string &name, const Weapon &weapon): _weapon(weapon),
		_name(name) {}

void	HumanA::attack() const
{
	cout << _name << " attacks with their " << _weapon.getType() << endl;
}
