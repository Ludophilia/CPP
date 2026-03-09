/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:29:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/03 19:00:20 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(String name)
{
	this->_name = name;
}

void	Zombie::annouce(void) const
{
	std::cout << this->_name << ":"
			  << " BraiiiiiiinnnzzzZ..."
			  << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "zombie '" << this->_name << "'"
			  << " destroyed."
			  << std::endl;
}
