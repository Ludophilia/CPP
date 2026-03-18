/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:21:14 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/18 01:42:48 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scav00;
	ScavTrap	scav01("scav01");

	scav00.attack("g0d");
	scav00 = scav01;
	scav00.attack("g0d");
	scav00.guardGate();

	for (int i = 0; i < 51; i++)
		scav01.attack("d0g");
	scav01.guardGate();

	ClapTrap *scav02 = new ScavTrap(scav01);
	scav02->attack("d0g");

	scav00 = ScavTrap();
	scav00.beRepaired(20000);
	scav00.takeDamage(42000);
	scav00.attack("em1");
	scav00.beRepaired(20000);
	delete scav02;
}
