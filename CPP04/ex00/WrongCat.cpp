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

WrongCat::WrongCat()
{
	type = "WrongCat";
	cout << "WrongCat default constructor called" << endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src)
{
	cout << "WrongCat copy constructor called" << endl;
}

WrongCat::~WrongCat()
{
	cout << "WrongCat default destructor called" << endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	cout << "* woem is meow backwards *" << endl;
}
