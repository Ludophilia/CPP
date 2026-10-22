/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:21:46 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/22 23:40:30 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	// _attackDmg = 20; // Ambiguous what? How many objects are there?
	cout << "DiamondTrap default constructor called (" << this << ")" << endl;
}

DiamondTrap::~DiamondTrap()
{
	cout << "DiamondTrap default destructor called (" << this << ")" << endl;
}
