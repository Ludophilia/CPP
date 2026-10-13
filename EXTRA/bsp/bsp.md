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
				and b. In 2d, as we've seen before, its either (0, 0, 1) or
				(0, 0, -1).

				- that means that it's that unit vector z component sign and
				sin(θ) and thus the angle θ that determines the sign of the
				cross product while the angle θ and the magnitudes 
				determine if the result will be zero or not.
					- sin(θ) = 0 OR sin(pi) = 0;
					- sin(θ) > 0 when θ is ]0; pi[ 
					- sin(θ) < 0 when θ is ]pi; 2pi[

		- z = 0 means:
			- One or both vectors a and b has length 0. |a|, |b| or both equal 0. 
			- their polar angle is either 0 (a and b are identical) or pi (a and b are opposites): 

		- z > 0 means:
			- that the polar angle is ]0; pi[ (+) and the unit vector n is (0, 0, 1) (+) 
			- or that the polar angle is ]pi; 2pi[ (-) and the unit vector n is (0, 0, -1) (-)

		- z < 0 means:
			- that the polar angle is ]pi; 2pi[ (-) and the unit vector n is (0, 0, 1) (+)
			- that the polar angle is ]0; pi[ (+) and the unit vector n is (0, 0, -1) (-)

- Reference
	- https://brilliant.org/courses/vectors/?from_llp=advanced-math 
	- https://www.mathsisfun.com/algebra/vectors-cross-product.html	


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
		BC,BP or CA,CP will be 0 and, as sin(0) = 0 and 
		a x b = |a| * |b| * sin(θ) * n, the cross product will be 0.
		- OR on any vertex A, B, or C. Here, one of the magnitude |AP|, |BP|,
		or |CP| will be 0, and, as a cross product is proportional to the 
		product of its magnitudes, the result will be zero. 

	- If the point P is inside the triangle A B C:
		- The cross product ABxAP; BCxBP or CAxCP always the same sign,
		negative or positive.
		- Why? I don't have a proof formal enough for this. 
			- I know the cross product sign depend on the sine and the unit
			vecor n.
				- When 


- Reference:
	- https://hackmd.io/community/@ChloeIsCoding/r19Mge-fll