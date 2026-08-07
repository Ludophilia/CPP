/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:29:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 21:34:44 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const string &name): _name(name)
{
}

Zombie::~Zombie()
{
	cout << _name << " the Zombie fainted." << endl;
}

void	Zombie::annouce(void) const
{
	cout << _name << ":" << " BraiiiiiiinnnzzzZ..." << endl;
}
