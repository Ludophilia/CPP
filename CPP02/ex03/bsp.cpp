/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/08 21:53:52 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static const Fixed xP2D(const Vector &lhs, const Vector &rhs)
{
	return (lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Vector	pa(a.getX() - point.getX(), a.getY() - point.getY());
	const Vector	pb(b.getX() - point.getX(), b.getY() - point.getY());
	const Vector	pc(c.getX() - point.getX(), c.getY() - point.getY());

	return (xP2D(pa, pb) > 0 && xP2D(pb, pc) > 0 && xP2D(pc, pa) > 0);
}

// Using fixed point numbers: avoids potentially "unsafe" comparisons involving
// floating point numbers. puts in good use the work that has been done before.
