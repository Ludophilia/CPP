/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 22:16:17 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/12 21:47:34 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AMateria (Abstract Materia)
//		= Ice (Concrete Materia)
//		= Cure

// ICharacter (Interface Character)
//		= Character 

// IMateriaSource (Interface MateriaSource)
//		= MateriaSource

#include <iostream> // REMOVE

int		main()
{
	std::cout << "Ca compile 🥹" << std::endl;
	
	// ICharacter			*me = new Character("me");
	// ICharacter			*bob = new Character("bob");
	// IMateriaSource		*src = new MateriaSource();
	// AMateria			*tmp;


	// src->learnMateria(new Ice()); // source learns "templates" of Materia to create
	// 							  // them when needed via createMateria using just a string
	// 							  // that identifies its type.
	// src->learnMateria(new Cure());


	// tmp = src->createMateria("ice"); // What's for? It doesn't leak?
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);


	// me->use(0, *bob); // * shoots an ice bolt at bob *$
	// me->use(1, *bob); // * heals bob's wounds *$


	// delete src;
	// delete me;
	// delete bob;
	// // delete tmp;


	return (0);
}
