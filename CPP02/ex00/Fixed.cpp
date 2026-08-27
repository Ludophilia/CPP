/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:04:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/27 19:41:28 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _rawValue(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &src)//: _rawValue(src.getRawBits())
{
	cout << "Copy constructor called" << endl;
	_rawValue = src.getRawBits();
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &rhs)
		_rawValue = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (_rawValue);
}

void	Fixed::setRawBits(const int raw)
{
	_rawValue = raw;
}
