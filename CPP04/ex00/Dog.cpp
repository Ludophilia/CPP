/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:35:46 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/19 23:02:26 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src): Animal(src)
{
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Default Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "* Shakespearian dog howls *" << std::endl;
}
