/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:35:46 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/29 23:09:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	cout << "Dog default constructor called" << endl;
}

Dog::Dog(const Dog &src): Animal(src)
{
	cout << "Dog copy constructor called" << endl;
}

Dog::~Dog()
{
	cout << "Dog default destructor called" << endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

void	Dog::makeSound() const
{
	cout << "* woof *" << endl;
}
