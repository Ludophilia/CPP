/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:04:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/09/07 22:54:30 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
Why returning by Value (Fixed) instead of Reference ((const)Fixed &)?
	Operators *+/-: 
		- Had we had to return by Reference, a reference to a temporary object 
		that would die as soon as the function has done executing would have  
		been returned instead...
		- Returning by Value means the temporary Fixed object used inside the  
		function definition will be copied by the caller... 

	Prefix (++a, -arr):
		- In the case of a prefix incrementation, there's no need to return
		a new copy of anything, just the original object as it is for further
		modification. Returning by Reference instead of by Value therefore
		is totally justified.

	Postfix (a++): 
		- Similarly to the operators *+/-, returning by Value (Fixed)
		instead of Reference ((const)Fixed &) means the temporary Fixed object
		used inside the function definition will be copied by the caller.
*/

Fixed::Fixed():
	_rawValue(0)
{
	// cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int intVal):
	_rawValue(intVal << _fractBits)
{
	// cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float floatVal):
	_rawValue(roundf(floatVal * (1 << _fractBits)))
{
	// cout << "Float constructor called" << endl;
}

Fixed::Fixed(const Fixed &src):
	_rawValue(src.getRawBits())
{
	// cout << "Copy constructor called" << endl;
}

Fixed::~Fixed()
{
	// cout << "Destructor called" << endl;
}

int		Fixed::getRawBits() const
{
	return (_rawValue);
}

void	Fixed::setRawBits(const int raw)
{
	_rawValue = raw;
}

int		Fixed::toInt() const
{
	return (_rawValue >> _fractBits);
}

float	Fixed::toFloat() const
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
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++()
{
	return (++_rawValue, *this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	prev = *this;

	return (_rawValue++, prev);
}

Fixed	&Fixed::operator--()
{
	return (--_rawValue, *this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	prev = *this;

	return (_rawValue--, prev);
}

// Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
// {
// 	return (lhs <= rhs ? lhs : rhs);
// }

// const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
// {
// 	return (lhs <= rhs ? lhs : rhs);
// }

// Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
// {
// 	return (lhs >= rhs ? lhs : rhs);
// }

// const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
// {
// 	return (lhs >= rhs ? lhs : rhs);
// }

ostream	&operator<<(ostream &lhs, const Fixed &rhs)
{
	return (lhs << rhs.toFloat());
}
