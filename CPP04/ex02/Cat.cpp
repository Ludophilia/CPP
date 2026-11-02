/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:16:56 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/02 21:28:43 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): _brain(new Brain)
{
	cout << "Cat default constructor called" << endl;
	type = "Cat";
}

Cat::Cat(const Cat &src): AAnimal(src), _brain(new Brain(*src._brain)) 
{
	cout << "Cat copy constructor called with brain " << _brain 
		 << " from " << src._brain << endl;
}

Cat::~Cat()
{
	cout << "Cat default destructor called" << endl;
	delete _brain;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
		*_brain = *rhs._brain;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	cout << "😾💬" << endl;
}
