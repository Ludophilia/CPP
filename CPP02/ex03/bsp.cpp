/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/09/12 18:45:02 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	(void)a; (void)b; (void)c; // a, b, c the vertices of our beloved triangle
	(void)point; // point the point to check

	// A point is defined by their x and y coordinates. 

	// How can I use bsp for checking if a Point is INSIDE a triangle ?

	/*
	- What does bsp DO, USUALLY ?
	
		- Helps with rendering? How? Recursively splitting up space into two.
		Organize splitted space into a binary tree. Use tree for figuring out how
		to efficiently render a 3d space by finding and painting the closest elements
		to the "camera" and ignoring those which are obstructed by them...
		- 
		- 
	
	- What does bsp have to do with our triangle problem ?

	*/
	
	// returns:
	// 		== true if the point is INSIDE the triangle a b c (NOT on the edges or on
	// 		the vertices a, b, c)
	// 		== false otherwise
	return (false);
}
