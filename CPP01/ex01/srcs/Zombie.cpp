/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:29:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/10 20:04:53 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::setName(const string &name)
{
	_name = name;
}

void	Zombie::annouce(void) const
{
	cout << _name << ":" << " BraiiiiiiinnnzzzZ..." << endl;
}
