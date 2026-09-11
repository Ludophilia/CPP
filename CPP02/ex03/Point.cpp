/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:55 by jegerman          #+#    #+#             */
/*   Updated: 2026/09/11 20:14:55 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point &src): _x(src._x), _y(src._y) {}

Point::~Point() {}

const char *Point::InvalidOperation::what() const throw()
{
	return ("Operator not implemented");
}

Point	&Point::operator=(const Point &rhs)
{ 
	throw InvalidOperation();
	return ((void)rhs, *this);
}
