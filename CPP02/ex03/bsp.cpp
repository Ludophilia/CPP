/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/09 23:10:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>

static const Fixed xP2D(const Vector &lhs, const Vector &rhs)
{
	Fixed fixed(lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX());

	std::cout << fixed << std::endl;

	return (fixed);
	// return (lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX());
}

// Improvements later...
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Vector	ab(b.getX() - a.getX(), b.getY() - a.getY());
	const Vector	ap(point.getX() - a.getX(), point.getY() - a.getY());

	const Vector	bc(c.getX() - b.getX(), c.getY() - b.getY());
	const Vector	bp(point.getX() - b.getX(), point.getY() - b.getY());

	const Vector	ca(a.getX() - c.getX(), a.getY() - c.getY());
	const Vector	cp(point.getX() - c.getX(), point.getY() - c.getY());

	// return (xP2D(pa, pb) > 0 && xP2D(pb, pc) > 0 && xP2D(pc, pa) > 0);

	std::cout << std::endl;

	xP2D(ab, ap);
	xP2D(bc, bp);
	xP2D(ca, cp); 
	
	return (0);

}

// Using fixed point numbers: avoids potentially "unsafe" comparisons involving
// floating point numbers. puts in good use the work that has been done before.



// static const Fixed xP2D(const Vector &lhs, const Vector &rhs)
// {
// 	Fixed fixed(lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX());

// 	std::cout << fixed << std::endl;

// 	return (fixed);
// 	// return (lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX());
// }

// bool bsp(Point const a, Point const b, Point const c, Point const point)
// {
// 	const Vector	pa(a.getX() - point.getX(), a.getY() - point.getY());
// 	const Vector	pb(b.getX() - point.getX(), b.getY() - point.getY());
// 	const Vector	pc(c.getX() - point.getX(), c.getY() - point.getY());

// 	// return (xP2D(pa, pb) > 0 && xP2D(pb, pc) > 0 && xP2D(pc, pa) > 0);

// 	std::cout << std::endl;
// 	return (xP2D(pa, pb), xP2D(pb, pc), xP2D(pc, pa), 0);

// }