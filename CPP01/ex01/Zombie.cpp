/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:29:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/04 16:47:51 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::setName(String name)
{
	this->_name = name;
}

void	Zombie::annouce(void) const
{
	std::cout << this->_name << ":"
			  << " BraiiiiiiinnnzzzZ..."
			  << std::endl;
}
