# BSP

## What does bsp DO, USUALLY ?

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
 and ignoring those which are obstructed by them...`

- Effect: Faster framerate...
	
## BSP and the In triangle Point Problem

What does bsp have to do with our triangle problem ?

- Turns out I was completely off tracks with this one.

- We don't really use BSP but something that gets conceptually close
to it: Testing the cross product of different vectors formed by the vertices
A B C and the Point.

## The Cross Product (v1 x v2)

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
	
- In 2d, everything amount to that z component and especially its sign:
	- That sign varies according to the angle θ (theta) formed by a and b, from a
	to b.
		- Another formula for the cross product is:
			- a x b = |a| * |b| * sin(θ) * n
				- |a| and |b| are magnitudes, positive OR zero.
				- n is an unit vector (magnitude 1), perpendicular to both a 
				and b.
					- In 2d, as we've seen before, it must be (0, 0, 1) or
					(0, 0, -1) depending on how are computed the angles and
					between the two vectors.
					- I will use from now on directed angles from a to b with 
					values [0 ; 2pi] and (0, 0, 1) as unit vector.

				- In that configuration, it's sin(θ) and thus the angle θ that determines the sign of the cross product while the angle θ and
				the magnitudes |a| and |b| determine if the result will be zero or not.

		- z = 0 means:
			- One or both vectors a and b has length 0. 
				- |a| = 0 AND / OR |b| = 0. 
			- their polar angle is either 0 (a and b are identical) or pi (a 
			and b are opposites):
				- sin(θ) = 0 OR sin(pi) = 0;

		- z > 0 means:
			- that the polar angle θ is ]0; pi[ as sin(θ) > 0

		- z < 0 means:
			- that the polar angle θ is ]pi; 2pi[ as sin(θ) < 0
	
- References
	- https://brilliant.org/courses/vectors/?from_llp=advanced-math to learn
	some basics around vectors
	- https://www.mathsisfun.com/algebra/vectors-cross-product.html to discover
	the cross product, some formulas...
	- https://www.geogebra.org/m/psMTGDgc to see how the cross product according
	to the angles and the relative position of e
	- https://www.desmos.com/calculator to visualize sin(x) on [-2pi; 2pi]

## The Cross Product and the Inside triangle Point Problem

- We need to know if a point P is inside a triangle or not.

- In a 2d plane, for a triangle A B C and a Point P, one of the ways to determine 
this is to compute the cross product of different vectors and to compare 
their signs / results.

- One possible configuration of vectors and cross product is the following:
	- AB x AP: AB being one edge of the triangle ABC taken as a vector
	and AP, the vector that goes from A to P.
	- BC x BP: BC, another edge of ABC and BP, the vector from B to P.
	- CA x CP: CA: the last uncovered edge of ABC and CP, the vector that
	from B to P.

- As seen in the last chapter, on a 2d plane, the cross product amount to a
scalar, the value of the z component.

	- Any of those cross product will amount to 0 if the Point P being tested
	is:
		- on any of the edge AB, BC or CA. In those cases, the angles AB,AP ; 
		BC,BP or CA,CP will be 0:
			- sin(0) = 0 and a x b = |a| * |b| * sin(θ) * n.

		- OR on any vertex A, B, or C. 
			- |AP| = 0 or |BP| = 0 or |CP| will be 0 and again,
			a x b = |a| * |b| * sin(θ) * n. 

	- If the point P is inside the triangle A B C:
		- The cross product ABxAP; BCxBP or CAxCP will always have the same sign,
		negative or positive.

		- ABxAP; BCxBP or CAxCP test the position of P relative to the edges
		of the triangle ABC.

		When P is inside ABC:

			- P divide ABC in 3 new triangles APB BPC APC. None of the
			angles in those triangles have an angle of pi or 0 radians, as
			they are non-degenerate triangles (their points are not colinear /
			on the same line) and the sum of each triangle angles will be pi radians.

			- P is above AB, BC and CA when each of those segments are used as
			references (plan seen alternatively with AB, BC and CA as segments
			parallel to the frame and close to its lower half).
				- That guarantees the orientation of the 3 angles (AB, AP) ; 
				(BC, BP) and (AC, AP) will remain consistent. If P is inside
				ABC, (AB, AP), (BC, BP) and (AC, AP) will describe the same
				type of angle:
					- one formed with one segment of ABC and a point P that 
					is above that segment when that segment is taken as 
					reference.
					- with an angle between ]0; pi[

				- Depending on the relative position of A B C, the angles 
				(AB, AP) from AB to AP, (BC, BP) from BC to BP and (AC, AP)
				from AC to AP could be:
					- between ]0; pi[ counter-clockwise so ]0; pi[ 
					- or ]0; pi[ clockwise so ]0; -pi[ or ]pi; 2pi[
					- As explained before:
						- When the angle is ]0; pi[, sin(θ) > 0 and all
						of those cross product will be positive.
						- When the angle is ]pi; 2pi[ sin(θ) < 0 and all
						of those cross product will be negative.

		When P is outside ABC however, not on edges or any of the vertices:
			- The angles (AB, AP), (BC, BP) and (AC, AP) will describe two
			type of angle:
				- Some angles will retain the same configuration as when P is 
				inside ABC with P being above the segments AB, BC or AC
				- While at least one of those angles will describe P as being
				below one the segments AB, BC or AC.
	
			- Some angles will then have a positive polar angle ]0; pi[ while 
			others will have a negative one ]0; -pi[, OR the opposite, depending
			on the relative position of the points A B C.
				- The 3 cross product (ABxAP), (BCxBP) and (ACxAP) will not
				have the same sign.

- References:
	- https://hackmd.io/community/@ChloeIsCoding/r19Mge-fll for an implementation
	of the test with cross products and other explanations.