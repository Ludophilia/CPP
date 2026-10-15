/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:21:14 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/15 22:41:04 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	clap00; // Default constructor
	ClapTrap	clap01("01"); // string constructor
	ClapTrap	clap02("02"); // string constructor
	// ClapTrap	clap03("03"); // string constructor
	ClapTrap	clap01a = clap01; // copy construtor
	// ClapTrap	clap02a(clap02); // copy construtor
	// ClapTrap	clap03a = ClapTrap("03"); // string constructor

	clap00 = clap01; // copy assignment operator
	for (int i = 0 ; i < 11; i++)
		clap00.attack("the wall");
	clap00.beRepaired(10);
	clap02.attack("a barrel of explosives");
	clap02.takeDamage(20);
	clap02.attack("the wall");
	clap02.beRepaired(20);
	// clap03.attack("01");
	// clap03.beRepaired(20);
}
