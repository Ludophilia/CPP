/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:32:45 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/24 01:27:58 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#define ANIMAL_NB (4)

int	main(void)
{
	static AAnimal	*animals[ANIMAL_NB];
	// AAnimal 			new_animal; // Won't work

	try
	{
		for (int i = 0 ; i < ANIMAL_NB ; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
			std::cout << animals[i]->getType() << " " << std::endl;
			animals[i]->makeSound();
		}

		Dog	new_dog(*static_cast<Dog *>(animals[0]));
		std::cout << new_dog.getType() << " " << std::endl;
		new_dog.makeSound();
		Cat	new_cat(*static_cast<Cat *>(animals[0]));
		std::cout << new_cat.getType() << " " << std::endl;
		new_cat.makeSound();
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		for (int i = 0 ; i < ANIMAL_NB ; i++)
			delete animals[i];
		return (1);
	}

	for (int i = 0 ; i < ANIMAL_NB ; i++)
		delete animals[i];
	return (0);
}
