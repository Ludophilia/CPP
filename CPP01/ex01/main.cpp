/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:57:39 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/10 20:55:12 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void		unleashHorde(const string &name, const int nbr)
{
	const Zombie * const	horde = zombieHorde(nbr, name);

	for (int i = 0; i < nbr; i++)
		horde[i].annouce();
	delete[] horde;
}

int	main()
{
	try
	{
		unleashHorde("Matt", 4);
	}
	catch (const std::bad_alloc& e)
	{
		cerr << e.what() << endl;
		return (1);
	}
	return (0);
}
