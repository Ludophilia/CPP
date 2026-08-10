/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:09:55 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/10 19:59:45 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, string name)
{
	Zombie * const	zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return (zombies);
}
