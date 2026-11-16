/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 22:16:17 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/16 23:53:23 by jegerman         ###   ########.fr       */
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
	=> MateriaSource ([x] operator=, [x] learnMateria, [x] createMateria, [x] leaks)

	=> [x] Test what happens when trying to add to an full Inventory?

	
= ICharacter 
	=> Character ([ ] operator=, [x] equip, [x] use, [ ] unequip, [ ] leaks)

= Inventory
	=> [ ] operator=, [x] use, [x] add, [ ] remove, [x] get, [ ] 
	=> operator= already in MateriaSource and Character copy constructor and 
	operator=, use in Character use, add in Character equip, remove in 
	Character unequip, get in MAteriaSource createMateria

*/

#include <cassert>

void	materiaSourceLifecycleTestCase()
{
	Character		yuffie("Yuffie"), vincent("Vincent");
	MateriaSource	source0, source1;
	AMateria		*m1, *m2;	

	try
	{
		m1 = source0.createMateria("ice"); // won't work
		assert(m1 == NULL);
		m1 = source0.createMateria("cure");
		assert(m1 == NULL);
		source0.learnMateria(NULL);
		for (int i = 0; i < (4 + 1); i++)
		{
			m1 = !(i % 2) ? (AMateria *)(new Ice()) : (new Cure());
			source0.learnMateria(m1);
		}
		cout << endl;
		delete m1; // because there 4 + 1
		
		m1 = source0.createMateria("ultima");
		assert(m1 == NULL);
		m1 = source0.createMateria("Ice");
		assert(m1 == NULL);
		m1 = source0.createMateria("Cure");
		assert(m1 == NULL);
		m1 = source0.createMateria("ice"); // will because source now knows ice and cure
		assert(m1 != NULL);
		m1->use(yuffie);
		cout << endl;
		delete m1;

		source1 = source0; // using source1 from source0
		m2 = source1.createMateria("ICE");
		assert(m2 == NULL);
		m2 = source1.createMateria("CURE");
		assert(m2 == NULL);
		m2 = source1.createMateria("cure");
		assert(m2 != NULL);
		m1 = source1.createMateria("ice");
		assert(m1 != NULL);
		m2->use(yuffie);
		m1->use(vincent);
		m2->use(vincent);
		delete m1;
		delete m2;
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << endl;
	}
}

void	characterAndMateriaInterfacesGeneralTestCase()
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
}

int		main()
{
	// characterAndMateriaInterfacesGeneralTestCase();
	materiaSourceLifecycleTestCase();
	return (0);
}
