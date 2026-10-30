/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:56:37 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/29 23:12:54 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	cout << "Animal default constructor called" << endl;
}

Animal::Animal(const Animal &src): type(src.type)
{
	cout << "Animal copy constructor called" << endl;
}

Animal::~Animal()
{
	cout << "Animal default destructor called" << endl;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

const string	&Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	cout << "* LOUD AND UNBEARABLE ANIMAL NOISE *" << endl;
}
