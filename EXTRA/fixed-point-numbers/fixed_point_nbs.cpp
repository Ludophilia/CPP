/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point_nbs.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 22:57:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/27 23:05:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

using	std::cout;
using	std::endl;

// https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html
int	main()
{
	// 27/08/26: What's that mess ?

	// What's a fixed point number to begin with?

	// A fixed point number is:

	// 	- A whole part
	// 	- A fractional part

	//  - Usually stored in integers

	// 	- the point is always at the same spot, meaning there's
	// 		- a fixed number of digits for the whole part
	//		- a fixed number of digits for the fractional part
	
	// The point position affect where the value of each digit.
	// 		- In a number in base b, the digit d0 at the left of the point has a value of
	//      d * b^0.
	//		- After the point to the right, the digit d-1 has a value of  d * b^-1
	//		- After the point to the left, the digit d0 has a value of  d * b^0
	//      - The further we go to the left, 

	// The problem NOW is how we express that in code...



	// 27/08/26: That's what I did in March 2026 under stress. I don't even remember
	// what that means... I guess it's conversions to Int or Float of fixed point
	// numbers, but I got to be sure... Let's see that shi tomorrow....
	
	// cout << "3.25 -> " << (3.25 << 16) << endl;
	// cout << "42 fixed -> " << (42 << 16) << endl; // 42 fixed -> 2752512

	// cout << "42 fixed -> " << (42 * (1 << 16)) << endl; // 42 fixed -> 2752512

	
	// cout << "42 int -> " << (2752512 >> 16) << endl; // 42 int -> 42
	// cout << "42 int -> " << (2752512 / (1 << 16)) << endl; // 42 int -> 42

	// cout << "3.25 fixed -> " << (3.25 * (1 << 16)) << endl; // 3.25 fixed -> 212992
	// cout << "3 int -> " << (212992 / (1 << 16)) << endl; // 3 int -> 3
	// cout << "3 int -> " << (212992 >> 16) << endl; // 3 int -> 3

	// cout << "0.25 fixed -> " << (212992 & 0xFFFF) / (float)(1 << 16) << endl; // 0.25 fixed -> 0.25

	// cout << "" << (212992 & ~(1 << 16)) << endl;

	return 0;
}
