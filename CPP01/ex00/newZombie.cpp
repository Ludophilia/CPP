/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:09:55 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/03 18:38:04 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(String name)
{
	Zombie	*zombie;

	zombie = new Zombie(name);
	if (zombie == NULL)
		return (NULL);
	return (zombie);
}
