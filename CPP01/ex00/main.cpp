/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:57:39 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 21:32:23 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void brainz()
{
	const Zombie	*ralph = new Zombie("Ralph");

	randomChump("James");
	ralph->annouce();
	delete ralph;
}

int	main()
{
	try
	{
		brainz();
	}
	catch (const std::bad_alloc& e)
	{
		cerr << e.what() << endl;
		return (1);
	}
	return (0);
}
