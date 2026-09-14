/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/09/14 23:05:02 by jegerman         ###   ########.fr       */
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
	
		- Helps with rendering? How? Recursively splitting space into two.
		A space is splitted up. And the two splitted spaces are also splitted
		into two, until a condition is reached.
		That process results into a binary tree, with the original space as
		root, the two subspaces as its left / right children and so on... with 
		(usually ???) a left / right logic that encodes their relative position 
		to each other (Front / Back?).
 
		- COMBINED with other rendering techniques like Raycasting, that
		tree can help figuring out how to efficiently render a 3d scene (or at
		least some elements of it like the walls, the static scenery...)
		by finding and painting FIRST the elements CLOSEST to the "camera"
		 and ignoring those which are obstructed by them...
	
		- Effect: Faster framerate...
		- 
	
	- What does bsp have to do with our triangle problem ?

		- To be honest, I don't really know... And actually, the use of BSP here
		may be initially seen as bizarre or overkill, at least from my point of view...

			- To test if a Point P(x, y) is in a triangle T{A, B, C}, I've come 
			to figure that a simple test of intervals might help to understand:
				- if x is in [min_x(T); max_x(T)]
				- and if y is in [min_y(T); max_y(T)]
				- the Point is in the triangle

			- The problem is that this test also works when the Point is one
			of the vertices A B C, and I suspect on the EDGES as well...

				- THat might be HERE that the BSP technique show its strength,
				But I'm not sure...

	*/
	
	// returns:
	// 		== true if the point is INSIDE the triangle a b c (NOT on the edges or on
	// 		the vertices a, b, c)
	// 		== false otherwise
	return (false);
}
