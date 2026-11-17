/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:32:45 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/30 21:28:05 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main()
{
	const Animal		*meta = new Animal();
	const Animal		*i = new Cat();
	const Animal		*j = new Dog();
	const WrongAnimal	*wi = new WrongCat();

	cout << endl;
	cout << meta->getType() << " " << endl;
	meta->makeSound();
	cout << i->getType() << " " << endl;
	i->makeSound();
	cout << j->getType() << " " << endl;
	j->makeSound();
	cout << wi->getType() << " " << endl;
	wi->makeSound();

	cout << endl;
	delete meta;
	delete i;
	delete j;
	delete wi;
	return (0);
}
