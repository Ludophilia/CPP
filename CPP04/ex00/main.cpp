/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:32:45 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/20 00:01:58 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const Animal		*meta = new Animal();
	const Animal		*i = new Cat();
	const WrongAnimal	*wi = new WrongCat();
	const Animal		*j = new Dog();

	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	std::cout << wi->getType() << " " << std::endl;
	wi->makeSound(); // will NOT output the cat sound!
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();

	delete meta;
	delete i;
	delete wi;
	delete j;
	return (0);
}
