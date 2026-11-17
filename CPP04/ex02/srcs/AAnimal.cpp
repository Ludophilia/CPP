/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:56:37 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/31 18:44:04 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal")
{
	cout << "AAnimal default constructor called" << endl;
}

AAnimal::AAnimal(const AAnimal &src): type(src.type)
{
	cout << "AAnimal copy constructor called" << endl;
}

AAnimal::~AAnimal()
{
	cout << "AAnimal default destructor called" << endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

const string	&AAnimal::getType() const
{
	return (type);
}

void	AAnimal::makeSound() const
{
	cout << "👽💬" << endl;
}
