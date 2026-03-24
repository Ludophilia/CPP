/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:16:56 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/24 01:26:18 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): _brain(new Brain)
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &src): AAnimal(src), _brain(new Brain(*src._brain)) 
{
	std::cout << "Copy Cat constructor called" << std::endl;
	std::cout << "\t- Source Brain address: " << src._brain << std::endl;
	std::cout << "\t- New Brain address: " << this->_brain << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Default Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		*this->_brain = *rhs._brain;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "😾 *Victorian cat cries*" << std::endl;
}
