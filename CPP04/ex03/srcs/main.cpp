/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 22:16:17 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/17 22:41:54 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <cassert>

void	characterLifecycleTestCase()
{
	AMateria	*cure, *ice;
	Character	*cloud, tifa("Tifa"), rufus("Rufus"),
				scarlet("Scarlet");

	try
	{
		cure = new Cure();
		ice = new Ice();
		cloud = new Character("Cloud");

		// cout << cloud->getName() << ":" << endl;
		cloud->equip(ice);
		cloud->equip(cure);
		cloud->unequip(1);
		cloud->use(1, rufus);
		delete cure; // One way to manage unequipped materia
		cloud->use(0, rufus);

		// cout << tifa.getName() << ":" << endl;
		tifa = *cloud; // Again, testing if they are DEEP copies.
		delete cloud; // cloud's name will erase tifa's. How sad...
		tifa.use(1, scarlet);
		tifa.use(0, scarlet);
		// tifa.unequip(0); // Would have been nice if the method had returned  
		// the address of the unequipped Materia but that's not what its 
		// signature requires so I can't use that here...
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << endl;
	}
}

void	materiaSourceLifecycleTestCase()
{
	Character		yuffie("Yuffie"), vincent("Vincent");
	MateriaSource	*source0, source1;
	AMateria		*m1, *m2;

	try
	{
		source0 = new MateriaSource();

		m1 = source0->createMateria("ice"); // won't work
		assert(m1 == NULL);
		m1 = source0->createMateria("cure");
		assert(m1 == NULL);
		source0->learnMateria(NULL);
		for (int i = 0; i < (4 + 1); i++)
		{
			m1 = !(i % 2) ? (AMateria *)(new Ice()) : (new Cure());
			source0->learnMateria(m1);
		}
		delete m1; // because there 4 + 1
		
		m1 = source0->createMateria("ultima");
		assert(m1 == NULL);
		m1 = source0->createMateria("Ice");
		assert(m1 == NULL);
		m1 = source0->createMateria("ice"); // will because source now knows ice and cure
		assert(m1 != NULL);
		m1->use(yuffie);
		delete m1;

		source1 = *source0; // using source1 from source0
		delete source0; // ensuring materias in source1 are DEEP copies...
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
	materiaSourceLifecycleTestCase();
	cout << endl;
	characterLifecycleTestCase();
	cout << endl;
	characterAndMateriaInterfacesGeneralTestCase();
	return (0);
}
