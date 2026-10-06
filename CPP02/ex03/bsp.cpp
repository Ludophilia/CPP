/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/06 23:56:11 by jegerman         ###   ########.fr       */
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

		- Turns out I was completely off tracks with this one.

		- We don't really use BSP but something that gets conceptually close
		to it.

		Testing the cross product of different vectors formed by the vertices
		A B C and the Point.

		- Now I have to dwelve deeper on that... 

	// (5/10) [I think i get it better now. I have some notes somewhere else
		about this but to summarize:
		
			- The cross product (a x b) is an operation on 3d vectors, that is vectors
			which have a x y z component on the vector space.
			- A cross product (a x b) "compute" a new vector from its two original
			a and b vectors operands. 
			- That vector is ORTHOGONAL / PERPENDICULAR to both a and b.

			- Adapting that 3d operation on a 2d plane is as simple as setting
			the z component of those a and b vectors to 0.
			- So a = (xa, ya, 0) and b = (xb, yb, 0).

			- In that case, the cross product a x b or the vector a x b  would have
			as x, y and z component:
				- (ya*0 - 0*yb,  0*xb - xa*0, xa*yb - ya*xb)
				- => (0, 0, xa*yb - ya*xb)
				
			- In a 2d space, everything amount to that z component and especially
			its sign:
			
				- That sign varies according to the angle θ (theta) formed by a and b, from a
				to b.
				- z = 0 means that the polar angle is either 0 (a and b are identical) or pi (a and b are opposites )
				- z > 0 means that the polar angle is ]0; pi[
				- z < 0 means that the polar angle is ]pi; 2pi[

	// 6/10 
	
		- What does that z component has to do with our in triangle test?
		
		- It SEEMS (I will do some research on that BUT will NOT try to prove it myself)
		that if a point P is in the triangle ABC, the angles APB, BPC, CPA will
		all a polar angle between ]0; pi[ and THUS a POSITIVE cross product
		or z component.
		
		- One of the angles APB, BPC, CPA will have an angle of pi radians and
		one of the cross product will be 0 if P is on the edges of the triangle
		ABC
		
		- One of the angles APB, BPC, CPA will have an angle of ]pi; 2pi[ radians and
		one of the cross product will be NEGATIVE if P is OUTSIDE the triangle
		ABC		

		- One of the angles APB, BPC, CPA will have an angle of 0 radians and
		one of the cross product will be 0 again if P is on A, B or C.

		- SO:
			- The problem amount to testing if every cross product is stricly
			superior to zero.
	
		- Reference
				- https://brilliant.org/courses/vectors/?from_llp=advanced-math
	// 			- https://www.mathsisfun.com/algebra/vectors-cross-product.html	

	*/
	
	// returns:
	// 		== true if the point is INSIDE the triangle a b c (NOT on the edges or on
	// 		the vertices a, b, c)
	// 		== false otherwise
	return (false);
}
