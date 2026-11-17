/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:35:46 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/02 21:28:50 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): _brain(new Brain)
{
	cout << "Dog default constructor called" << endl;
	type = "Dog";
}

Dog::Dog(const Dog &src): AAnimal(src), _brain(new Brain(*src._brain)) 
{
	cout << "Dog copy constructor called with brain " << _brain 
		 << " from " << src._brain << endl;
}

Dog::~Dog()
{
	cout << "Dog default destructor called" << endl;
	delete _brain;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
		*_brain = *rhs._brain;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	cout << "🐶💬" << endl;
}
