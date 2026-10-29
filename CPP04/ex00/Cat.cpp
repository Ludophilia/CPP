/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:16:56 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/29 23:07:41 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	cout << "Cat default constructor called" << endl;
}

Cat::Cat(const Cat &src): Animal(src)
{
	cout << "Cat copy constructor called" << endl;
}

Cat::~Cat()
{
	cout << "Cat default destructor called" << endl;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

void	Cat::makeSound() const
{
	cout << "* meow *" << endl;
}
