/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:21:14 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/21 22:14:07 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	FragTrap	frag00;
	FragTrap	*frag01 = new FragTrap("Naive");

	cout << endl;
	for (int i = 0 ; i < 4 ; i++)
	{
		frag01->highFivesGuys();
		frag00.attack("Naive");
		frag01->takeDamage(30);
		cout << endl;
	}
	frag01->beRepaired(100);
	cout << endl;
	delete frag01;
}
