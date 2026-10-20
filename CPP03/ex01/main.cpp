/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:21:14 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/20 21:33:16 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	*scav00 = new ScavTrap();
	ScavTrap	scav01("01");

	scav00->guardGate();
	*scav00 = scav01;
	scav00->attack("a barrel of explosives");
	scav00->guardGate();
	scav00->takeDamage(42);
	scav00->beRepaired(42);

	delete scav00;
}
