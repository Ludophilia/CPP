/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:04:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/28 23:49:04 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():
	_rawValue(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &src)//:
//	_rawValue(src.getRawBits())
{
	cout << "Copy constructor called" << endl;
	_rawValue = src.getRawBits();
}

Fixed::Fixed(const int intVal):
	_rawValue(intVal << _fractBits)
{
	cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float floatVal):
	_rawValue(roundf(floatVal * (1 << _fractBits)))
{
	cout << "Float constructor called" << endl;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &rhs)
		_rawValue = rhs.getRawBits();
	return (*this);
}

int		Fixed::toInt(void) const
{
	return (_rawValue >> _fractBits);
}

float	Fixed::toFloat(void) const
{
	 // Why did you cast float the power of two?
	return (_rawValue / static_cast<float>(1 << _fractBits));
}

int		Fixed::getRawBits(void) const
{
	return (_rawValue);
}

void	Fixed::setRawBits(const int raw)
{
	_rawValue = raw;
}

ostream		&operator<<(ostream &out, const Fixed &rhs)
{
	return (out << rhs.toFloat());
}
