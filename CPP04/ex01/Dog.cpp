/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:35:46 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/30 23:08:05 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): _brain(new Brain)
{
	type = "Dog";
	cout << "Dog default constructor called" << endl;
}

Dog::Dog(const Dog &src): Animal(src), _brain(new Brain(*src._brain)) 
{
	cout << "Dog copy constructor called with brain " << endl;
	// cout << "\t- Source Brain address: " << src._brain << endl;
	// cout << "\t- New Brain address: " << _brain << endl;
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
