/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:35:46 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/24 00:46:53 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): _brain(new Brain)
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src): Animal(src), _brain(new Brain(*src._brain)) 
{
	std::cout << "Copy Dog constructor called with brain " << std::endl;
	std::cout << "\t- Source Brain address: " << src._brain << std::endl;
	std::cout << "\t- New Brain address: " << this->_brain << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Default Dog destructor called" << std::endl;
	delete this->_brain;
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
	std::cout << "🐕 *Shakespearian dog howls*" << std::endl;
}
