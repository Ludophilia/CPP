/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:16:56 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/19 23:03:10 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src): Animal(src)
{
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Default Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "* Victorian cat cries *" << std::endl;
}
