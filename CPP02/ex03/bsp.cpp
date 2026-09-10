/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/09/10 22:23:04 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c,Point const point)
{
	(void)a; (void)b; (void)c; // a, b, c the vertices of our beloved triangle
	(void)point; // point the point to check
	
	// returns:
	// 		== true if the point is INSIDE the triangle a b c (NOT on the edges or on
	// 		the vertices a, b, c)
	// 		== false otherwise
	return (false);
}
