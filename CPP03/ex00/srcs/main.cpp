/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:21:14 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/21 22:34:57 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	clap00;
	ClapTrap	clap01("Philosopher"); // string constructors
	ClapTrap	clap02("Adventurer");
	// ClapTrap	clap03 = ClapTrap("03");
	ClapTrap	clap01a(clap01); // copy construtors
	// ClapTrap	clap02a = clap02;

	cout << endl;
	clap00 = clap01; // copy assignment operator
	for (int i = 0 ; i < 11; i++)
		clap00.attack("the wall");
	clap00.beRepaired(10);
	cout << endl;

	clap02.attack("a barrel of explosives");
	clap02.takeDamage(420);
	clap02.attack("the wall");
	clap02.beRepaired(20);
	cout << endl;
}
