/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point_nbs.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 22:57:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/29 23:42:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <bitset>

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

	// ########################################################################

	// Here's some examples of fixed point numbers.

	// A 32 bits integer with 28 spot for the whole part.

	const int		_fractBits = 4; // 4 default
	int				_rawValue;
	int				_oriValue;

	cout << std::showbase;
	cout << "fractBits: (1<<" << _fractBits << ") => " 
		 << "(2^" << _fractBits << ") => "
	     << (1 << _fractBits)
		 << "."
		 << endl;
	// ########################################################################
	cout << "Integer or Float as rawValue:" 
		 << endl;

	_oriValue = 42;
	cout << "\t* original (dec): " << _oriValue << '\n'
		 << "\t* original (bits): " << std::bitset<16>(_oriValue)
		 << endl;
	_rawValue = (_oriValue << _fractBits); // <=
	cout << "\t* " << _oriValue << " as rawValue (dec): " << _rawValue << '\n' // -> 672
	     << "\t* " << _oriValue << " as rawValue (bin): " <<  std::bitset<16>(_rawValue) // -> 672
		 << '\n' << endl;

	_oriValue = 42.42; // ❌ Lost in translation :/ Hence the Float...
	cout << "\t* original (dec): " << _oriValue << '\n'
		 << "\t* original (bits): " << std::bitset<16>(_oriValue)
		 << endl;
	_rawValue = (_oriValue << _fractBits); // <= ✅
	// _rawValue = (42.42 << _fractBits); // <= ❌ expression must have integral or enum type
	_rawValue = (_oriValue << _fractBits); // <=
	cout << "\t* " << _oriValue << " as rawValue (dec): " << _rawValue << '\n' // -> 672
	     << "\t* " << _oriValue << " as rawValue (bin): " <<  std::bitset<16>(_rawValue) // -> 672
		 << endl;

	// ###############
	// cout << "Integer or Float as rawValue (alt, ✅ both int / float):" 
	// 	 << endl;
	// _rawValue = (42 * (1 << _fractBits)); // <=
	// cout << "\t* 42 (int) as rawValue (alt): "
	// 	 << _rawValue
	// 	 << endl; // -> 672
	// _rawValue = (42.42 * (1 << _fractBits)); // <=
	// cout << "\t* 42.42 (float) as rawValue (alt): "
	// 	 << _rawValue
	// 	 << endl; // -> 678
	// // ########################################################################
	// cout << "Integer or Float rawValue TO an Integer: (✅ both int / float)" 
	// 	 << endl;
	// _rawValue = (42 * (1 << _fractBits));
	// cout << "\t* 42 (int) rawValue TO an int: "
	// 	 << (_rawValue >> _fractBits) // <=
	// 	 << endl; // -> 42
	// _rawValue = (42.42 * (1 << _fractBits));
	// cout << "\t* 42.42 (float) rawValue TO an int: "
	// 	 << (_rawValue >> _fractBits) // <=
	// 	 << endl; // -> 42
	// _rawValue = (42.99 * (1 << _fractBits));
	// cout << "\t* 42.99 (float) rawValue TO an int: "
	// 	 << (_rawValue >> _fractBits) // <=
	// 	 << endl; // -> 42
	// _rawValue = (42.999999999999999 * (1 << _fractBits));
	// cout << "\t* 42.999999999999999 (float) rawValue TO an int: "
	// 	 << (_rawValue >> _fractBits) // <=
	// 	 << endl; // -> 43!?
	// // ###############
	// cout << "Integer or Float rawValue TO an Integer (alt, ✅ both int / float):" 
	// 	 << endl;
	// _rawValue = (42 << _fractBits);
	// cout << "\t* 42 (int) rawValue TO an int (alt): "
	// 	 << (_rawValue / (1 << _fractBits)) // <=
	// 	 << endl; // -> 42
	// _rawValue = (42.99 * (1 << _fractBits));
	// cout << "\t* 42.99 (float) rawValue TO an int: (alt) "
	// 	 << (_rawValue / (1 << _fractBits)) // <=
	// 	 << endl; // -> 42
	// _rawValue = (42.999999999999999 * (1 << _fractBits));
	// cout << "\t* 42.999999999999999 (float) rawValue TO an int: "
	// 	 << (_rawValue / (1 << _fractBits)) // <=
	// 	 << endl; // -> 43!?
	// // ########################################################################
		
	// cout << "Integer or Float rawValue TO a Float:" 
	// 	 << endl;


	
	// _rawValue = (42.42 * (1 << _fractBits));
	// cout << "\t* 42.42 (float) rawValue TO a float (alt): "
	// 	 << static_cast<float>(_rawValue) / (1 << _fractBits) // <=
	// 	 << endl; // -> 42.375
	// _rawValue = (42.99 * (1 << _fractBits));
	// cout << "\t* 42.99 (float) rawValue TO a float (alt): "
	// 	 << static_cast<float>(_rawValue) / (1 << _fractBits) // <=
	// 	 << endl; // -> 42.875
	// _rawValue = (42.999999999999999 * (1 << _fractBits));
	// cout << "\t* 42.999999999999999 (float) rawValue TO a float (alt): "
	// 	 << static_cast<float>(_rawValue) / (1 << _fractBits) // <=
	// 	 << endl; // -> 42.375

		 
	// #######################################################################

	// 27/08/26, 28/08/26: That's what I did in March 2026 under stress. 
	
	// I don't even remember what that means... I guess it's conversions to Int or Float of fixed point
	// numbers, but I got to be sure... Let's see that shi tomorrow tomorrow....
	// I'm not done yet...
	
	
	// cout << "3.25 -> " << (3.25 << 16) << endl;
	// cout << "3.25 fixed -> " << (3.25 * (1 << 16)) << endl; // 3.25 fixed -> 212992

	// cout << "3 int -> " << (212992 / (1 << 16)) << endl; // 3 int -> 3
	// cout << "3 int -> " << (212992 >> 16) << endl; // 3 int -> 3

	// cout << "0.25 fixed -> " << (212992 & 0xFFFF) / (float)(1 << 16) << endl; // 0.25 fixed -> 0.25

	// cout << "" << (212992 & ~(1 << 16)) << endl;

	return 0;
}
