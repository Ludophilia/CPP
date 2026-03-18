/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:21:14 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/18 21:21:03 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// So similar to ScavTrap that there should be another way to do that...
int	main(void)
{
	FragTrap	frag00;
	FragTrap	frag01("frag01");

	frag00.attack("g0d");
	frag00 = frag01;
	frag00.attack("g0d");
	frag00.highFivesGuys();

	for (int i = 0; i < 101; i++)
		frag01.attack("d0g");
	frag01.highFivesGuys();

	ClapTrap *frag02 = new FragTrap(frag01);
	frag02->attack("d0g");

	frag00 = FragTrap();
	frag00.takeDamage(99);
	frag00.attack("em1");
	frag00.beRepaired(99);
	frag00.takeDamage(101);
	frag00.attack("em1");
	frag00.beRepaired(99);
	delete frag02;
}
