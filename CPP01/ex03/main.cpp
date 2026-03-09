/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:57:39 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/09 13:39:33 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();
		// club.setType("some other type of club");
		// bob.attack();

		// delete clubx;
	}
	return (0);
}
