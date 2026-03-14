/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:04:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/15 00:28:13 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal): _value(intVal << _fbits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatVal): _value(roundf(floatVal * (1 << _fbits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

int		Fixed::toInt(void) const
{
	return (this->_value >> _fbits);
}

float	Fixed::toFloat(void) const
{
	return (this->_value / static_cast<float>(1 << _fbits));
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

// >, <, >=, <=, ==, and !=

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->_value > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->_value < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_value >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_value <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->_value == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_value != rhs.getRawBits());
}





std::ostream	&operator<<(std::ostream &out, const Fixed &rhs)
{
	return (out << rhs.toFloat());
}
