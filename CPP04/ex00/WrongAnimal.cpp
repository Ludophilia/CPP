/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:56:37 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/19 23:03:22 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	cout << "WrongAnimal default constructor called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src): type(src.type)
{
	cout << "WrongAnimal copy constructor called" << endl;
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal default destructor called" << endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

const string	&WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	cout << "* EVEN LOUDER AND MORE UNBEARABLE ANIMAL NOISE *" << endl;
}
