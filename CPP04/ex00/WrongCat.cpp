/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:16:56 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/19 23:03:10 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src)
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Default WrongCat destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "* Victorian cat cries *" << std::endl;
}
