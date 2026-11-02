/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:32:45 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/02 20:06:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

using std::cerr;

void	testAnimalArrayConstructionAndDestruction(const int animalNb)
{
	Animal	*animals[animalNb];
	int		pos = 0;

	try
	{
		while (pos < animalNb)
		{
			if (pos % 2 == 0)
				animals[pos] = new Dog();
			else
				animals[pos] = new Cat();
			cout << animals[pos]->getType() << " " << endl;
			animals[pos++]->makeSound();
			cout << endl;
		}
	}
	catch (const std::bad_alloc &e)
	{
		cerr << "Error: " << e.what() << endl;
	}
	while (--pos >= 0)
		delete animals[pos];
}

void	testIfAnimalDeepOrShallowCopy()
{
	try
	{
		Dog		dogA, dogB(dogA);
		cout << endl;
		Cat		catA, catB(catA);
		cout << endl;
	}
	catch (const std::bad_alloc &e)
	{
		cerr << "Error: " << e.what() << endl;
	}
}

int	main()
{
	testAnimalArrayConstructionAndDestruction(4);
	testIfAnimalDeepOrShallowCopy();
	return (0);
}
