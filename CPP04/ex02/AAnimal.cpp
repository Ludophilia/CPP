/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:56:37 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/24 01:26:46 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("Animal")
{
	std::cout << "Default AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src): type(src.type)
{
	std::cout << "Copy AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Default AAnimal destructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

const String	&AAnimal::getType(void) const
{
	return (this->type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "* Generic yet elegant animal sound *" << std::endl;
}
