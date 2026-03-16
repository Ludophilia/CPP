/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:21:14 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/16 22:47:24 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clap00;
	ClapTrap	clap01("01");
	ClapTrap	clap02("02");
	ClapTrap	clap03("03");
	ClapTrap	clap01a = clap01;
	ClapTrap	clap02a(clap02);
	ClapTrap	clap03a = ClapTrap("03");

	clap00 = clap01;
	for (int i = 0 ; i < 11; i++)
		clap00.attack("02");
	clap00.beRepaired(10);
	clap02.takeDamage(0);
	clap03.takeDamage(20);
	clap03.attack("01");
	clap03.beRepaired(20);
}
