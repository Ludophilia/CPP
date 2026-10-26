/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:21:14 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/26 22:53:23 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


int	main()
{
	DiamondTrap	diamond;

	cout << endl;

	diamond.attack("Dummy");


	// diamond.highFivesGuys(); // in-ambiguous (FragTrap)
	// diamond.guardGate(); // in-ambiguous (ScavTrap)

	// diamond.attack("Z"); // attack appears in one ClapTrap overrided in ScavTrap,
	//					  + and another ClapTrap, via FragTrap. So yes, 
	//					 calling attack on diamond is ambiguous. attack sure,
	//					but which one?
	// diamond.FragTrap::attack("A");
	// diamond.ScavTrap::attack("B");

	cout << endl;
}

// int	main()
// {
// 	FragTrap	frag00;
// 	FragTrap	*frag01 = new FragTrap("Naive");

// 	cout << endl;
// 	for (int i = 0 ; i < 4 ; i++)
// 	{
// 		frag01->highFivesGuys();
// 		frag00.attack("Naive");
// 		frag01->takeDamage(30);
// 		cout << endl;
// 	}
// 	frag01->beRepaired(100);
// 	cout << endl;
// 	delete frag01;
// }
