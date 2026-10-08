/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:55 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/08 20:18:08 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Fixed &x, const Fixed &y): _x(x), _y(y) {}

Point::Point(const Point &src): _x(src._x), _y(src._y) {}

Point::~Point() {}

float Point::fgetX() const
{
	return (_x.toFloat());
}

float Point::fgetY() const
{
	return (_y.toFloat());
}

const Fixed &Point::getX() const
{
	return (_x);
}

const Fixed &Point::getY() const
{
	return (_y);
}

Point	&Point::operator=(const Point &rhs)
{ 
	throw InvalidOperation();
	return ((void)rhs, *this);
}

const char *Point::InvalidOperation::what() const throw()
{
	return ("Operator not implemented");
}
