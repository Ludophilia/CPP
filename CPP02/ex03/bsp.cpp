/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/12 22:07:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream> // <== tmp

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Fixed abxap = (b.getX() - a.getX()) * (point.getY() - a.getY()) \
		- (b.getY() - a.getY()) * (point.getX() - a.getX());
	const Fixed bcxbp = (c.getX() - b.getX()) * (point.getY() - b.getY()) \
		- (c.getY() - b.getY()) * (point.getX() - b.getX());
	const Fixed caxcp = (a.getX() - c.getX()) * (point.getY() - c.getY()) \
		- (a.getY() - c.getY()) * (point.getX() - c.getX());

	// std::cout << '\n'
	// 		<< abxap << '\n'
	// 		<< bcxbp << '\n'
	// 		<< caxcp << '\n'
	// 		<< "all positive: " << (abxap > 0 && bcxbp > 0 && caxcp > 0) << '\n'
	// 		<< "all negative: " << (abxap < 0 && bcxbp < 0 && caxcp < 0) << '\n';
	
	return ((abxap > 0 && bcxbp > 0 && caxcp > 0) 
			|| (abxap < 0 && bcxbp < 0 && caxcp < 0));
}

// typedef Point Vector;

// static const Fixed xP2D(const Vector &lhs, const Vector &rhs)
// {
// 	Fixed fixed(lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX());

// 	return (fixed);
// }

// bool bsp(Point const a, Point const b, Point const c, Point const point)
// {
// 	const Vector	pa(a.getX() - point.getX(), a.getY() - point.getY());
// 	const Vector	pb(b.getX() - point.getX(), b.getY() - point.getY());
// 	const Vector	pc(c.getX() - point.getX(), c.getY() - point.getY());

// 	return (xP2D(pa, pb) > 0 && xP2D(pb, pc) > 0 && xP2D(pc, pa) > 0);
// }

// ===========================================================================

// static const Fixed xP2D(const Vector &lhs, const Vector &rhs)
// {
// 	Fixed fixed(lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX());

// 	std::cout << fixed << std::endl;

// 	return (fixed);
// 	// return (lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX());
// }

// Improvements later...
// bool bsp(Point const a, Point const b, Point const c, Point const point)
// {
// 	// const Vector	ab(b.getX() - a.getX(), b.getY() - a.getY());
// 	// const Vector	ap(point.getX() - a.getX(), point.getY() - a.getY());

// 	std::cout << std::endl;

// 	const Fixed abxap = (b.getX() - a.getX()) * (point.getY() - a.getY())
// 		- (b.getY() - a.getY()) * (point.getX() - a.getX());
// 	std::cout << abxap << std::endl;
	

// 	// const Vector	bc(c.getX() - b.getX(), c.getY() - b.getY());
// 	// const Vector	bp(point.getX() - b.getX(), point.getY() - b.getY());

// 	const Fixed bcxbp = (c.getX() - b.getX()) * (point.getY() - b.getY())
// 		- (c.getY() - b.getY()) * (point.getX() - b.getX());
// 	std::cout << bcxbp << std::endl;

// 	// const Vector	ca(a.getX() - c.getX(), a.getY() - c.getY());
// 	// const Vector	cp(point.getX() - c.getX(), point.getY() - c.getY());

// 	const Fixed caxcp = (a.getX() - c.getX()) * (point.getY() - c.getY())
// 		- (a.getY() - c.getY()) * (point.getX() - c.getX());

// 	std::cout << caxcp << std::endl;

// 	// return (xP2D(pa, pb) > 0 && xP2D(pb, pc) > 0 && xP2D(pc, pa) > 0);

// 	// std::cout << std::endl;

// 	// xP2D(ab, ap);
// 	// ab.getX() * ap.getY() - ab.getY() * ap.getX()
// 	// (b.getX() - a.getX()) * (point.getY() - a.getY()) 
// 	// - (b.getY() - a.getY()) * (point.getX() - a.getX())
// 	// xP2D(bc, bp);
// 	// xP2D(ca, cp);

	
	
// 	return (0);

// }

// Using fixed point numbers: avoids potentially "unsafe" comparisons involving
// floating point numbers. puts in good use the work that has been done before.

