/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:35:46 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/22 23:00:40 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): _brain(new Brain)
{
	this->type = "Dog";
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src): Animal(src), _brain(new Brain(*src._brain)) 
{
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;	
	std::cout << "Default Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		*this->_brain = *rhs._brain;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "* Shakespearian dog howls *" << std::endl;
}
