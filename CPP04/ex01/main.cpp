/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:32:45 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/22 23:00:45 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const Animal		*animal = NULL;
	const Animal		*cat = NULL;
	const Animal		*dog = NULL;
	try
	{
		animal = new Animal();
		cat = new Cat();
		dog = new Dog();
		
		// std::cout << animal->getType() << " " << std::endl;
		// animal->makeSound();
		// std::cout << cat->getType() << " " << std::endl;
		// cat->makeSound(); // will output the cat sound!
		// std::cout << dog->getType() << " " << std::endl;
		// dog->makeSound();

	}
	catch (const std::bad_alloc &e)
	{
		// It's not enough... Could leak everywhere...
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	delete animal;
	delete cat;
	delete dog;
	return (0);
}
