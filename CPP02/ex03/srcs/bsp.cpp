/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/14 20:27:33 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Fixed abxap = (b.getX() - a.getX()) * (point.getY() - a.getY()) \
		- (b.getY() - a.getY()) * (point.getX() - a.getX());
	const Fixed bcxbp = (c.getX() - b.getX()) * (point.getY() - b.getY()) \
		- (c.getY() - b.getY()) * (point.getX() - b.getX());
	const Fixed caxcp = (a.getX() - c.getX()) * (point.getY() - c.getY()) \
		- (a.getY() - c.getY()) * (point.getX() - c.getX());
	
	return ((abxap > 0 && bcxbp > 0 && caxcp > 0) 
			|| (abxap < 0 && bcxbp < 0 && caxcp < 0));
}
