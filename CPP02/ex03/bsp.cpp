/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/07 23:20:00 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float xP2D(const Vector &lhs, const Vector &rhs)
{
	return (lhs.fgetX() * rhs.fgetY() - lhs.fgetY() * rhs.fgetX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Vector	pa(a.fgetX() - point.fgetX(), a.fgetY() - point.fgetY());
	const Vector	pb(b.fgetX() - point.fgetX(), b.fgetY() - point.fgetY());
	const Vector	pc(c.fgetX() - point.fgetX(), c.fgetY() - point.fgetY());

	return (xP2D(pa, pb) > 0 && xP2D(pb, pc) > 0 && xP2D(pc, pa) > 0);
}
