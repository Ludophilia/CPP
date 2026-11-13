/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 22:16:17 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/13 22:49:53 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
// #include <iostream>

int		main()
{
	ICharacter			*me = new Character("me");
	ICharacter			*bob = new Character("bob");
	IMateriaSource		*src = new MateriaSource();
	AMateria			*tmp;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->use(0, *bob); // * shoots an ice bolt at bob *$
	me->use(1, *bob); // * heals bob's wounds *$

	delete src;
	delete me;
	delete bob;

	return (0);
}

// TODO
// [ ] Inventory
//		= [ ] How to manage the unequipped materia?
