/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:04:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/25 22:27:47 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _rvalue(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed::Fixed(const Fixed &src)
{
	cout << "Copy constructor called" << endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &rhs)
		setRawBits(rhs.getRawBits());
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (_rvalue);
}

void	Fixed::setRawBits(const int raw)
{
	_rvalue = raw;
}
