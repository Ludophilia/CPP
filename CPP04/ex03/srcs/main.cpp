/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 22:16:17 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/16 21:07:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
// #include <iostream>

/*

= AMateria
	=> Ice; Cure ([x] clone, [x] use)
	=> clone Already tested via materiaSource createMateria and use via Character use

= IMateriaSource 
	=> MateriaSource ([ ] operator=, [x] learnMateria, [x] createMateria, [ ] leaks)

	=> [] Test what happens when trying to add to an full Inventory?

	
= ICharacter 
	=> Character ([ ] operator=, [x] equip, [x] use, [ ] unequip, [ ] leaks)

= Inventory
	=> [ ] operator=, [x] use, [x] add, [ ] remove, [x] get, [ ] 
	=> operator= already in MateriaSource and Character copy constructor and 
	operator=, use in Character use, add in Character equip, remove in 
	Character unequip, get in MAteriaSource createMateria

*/
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
