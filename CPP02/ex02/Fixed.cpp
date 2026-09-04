/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:04:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/09/04 19:39:45 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():
	_rawValue(0)
{
	cout << "Default constructor called" << endl;
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

Fixed::Fixed(const Fixed &src):
	_rawValue(src.getRawBits())
{
	cout << "Copy constructor called" << endl;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

int		Fixed::getRawBits(void) const
{
	return (_rawValue);
}

void	Fixed::setRawBits(const int raw)
{
	_rawValue = raw;
}

int		Fixed::toInt(void) const
{
	return (_rawValue >> _fractBits);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawValue) / (1 << _fractBits));
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		_rawValue = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (_rawValue > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (_rawValue < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (_rawValue >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (_rawValue <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (_rawValue == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (_rawValue != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++()
{
	return (_rawValue += 1, *this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	prev = *this;

	return (_rawValue += 1, prev);
}

Fixed	&Fixed::operator--()
{
	return (_rawValue -= 1, *this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	prev = *this;

	return (_rawValue -= 1, prev);
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return (lhs <= rhs ? lhs : rhs);
}

const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	return (lhs <= rhs ? lhs : rhs);
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return (lhs >= rhs ? lhs : rhs);
}

const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	return (lhs >= rhs ? lhs : rhs);
}

ostream	&operator<<(ostream &lhs, const Fixed &rhs)
{
	return (lhs << rhs.toFloat());
}
