/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:56:37 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/19 23:59:52 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("Animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src): type(src.type)
{
	std::cout << "Copy Animal constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Default Animal destructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

const String	&Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "* Generic yet elegant animal sound *" << std::endl;
}
