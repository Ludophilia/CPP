/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:21:14 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/27 22:55:20 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap		defaultD;
	DiamondTrap		diamond("diamond");
	DiamondTrap		diamondCopy(diamond);

	cout << endl;

	defaultD.whoAmI();
	defaultD.highFivesGuys();
	diamondCopy.whoAmI();
	diamondCopy.highFivesGuys();
	cout << endl;
	defaultD.attack("dummy");
	defaultD.takeDamage(100);
	defaultD.beRepaired(100);
	cout << endl;
	diamondCopy.guardGate();
	diamondCopy.attack("dummy");
	diamondCopy.takeDamage(10);
	diamondCopy.beRepaired(10);

	cout << endl;
}
