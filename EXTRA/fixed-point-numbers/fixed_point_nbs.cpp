/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point_nbs.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 22:57:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/31 21:53:49 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <bitset>

#include "Fixed.hpp"

using	std::cout;
using	std::endl;

#define ALT false

// https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html
int	main()
{
	// 27/08/26: What's a fixed point number to begin with?

	// A fixed point number is:

	// 	- A whole part
	// 	- A fractional part

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

	// == An integer... to the fixed point number.
	// == A coefficient to "dilate" the fractional part of the original value
	// on the first N bits and express it as precisely as possible with the 
	// lower bits of that integer (a bit shaky as an explanation no?).
	// That way:
	//		# 0.125 will be 32 (0.125 * 256) if we choose to 'encode' the fractional part
	// 		on the first 8 bits (2**8 => 256)...
	//      # 0 will stay 0 (0 * 256)... 
	//		# 0.5 will be 128 (0.5 * 256)...

	// ########################################################################

	// Here's some examples of fixed point numbers.

	// A 32 bits integer with 28 spot for the whole part.

	const int		_fractBits = 8; // 8 default
	int				_oriValueInt;
	float			_oriValueFloat;
	int				_rawValueInt;

	cout << std::showbase
	     << "fractBits: (1<<" << _fractBits << ") => " 
		 << "(2^" << _fractBits << ") => "
		 << (1 << _fractBits)
		 << '\n'
		 << endl;

	cout << "Integer and Float as rawValue:" << endl;

	_oriValueInt = 42;
	cout << "\t* original (dec): " << _oriValueInt << '\n'
		 << "\t* original (bits): "
		 << std::bitset<16>(_oriValueInt).to_string().insert(_fractBits, ".")
		 << endl;
	_rawValueInt = ALT? (42 * (1 << _fractBits)) : (_oriValueInt << _fractBits); 
	cout << "\t* " << _oriValueInt << " as rawValue (dec): "
				   << _rawValueInt << '\n' // -> 10752 = 42 * 256
		 << "\t* " << _oriValueInt << " as rawValue (bits): "
		 		   <<  std::bitset<16>(_rawValueInt).to_string().insert(_fractBits, ".")
				   // -> 00101010.00000000 so 42.00
		 << '\n' << endl;

	// _oriValueInt = 42.5; // ❌ will lose fractional part
	_oriValueFloat = 42.5;
	cout << "\t* original (dec): " << _oriValueFloat << '\n'
		 << "\t* original (bits, casted): "
		 << std::bitset<16>(_oriValueFloat).to_string().insert(_fractBits, ".") // ❌
		 << endl;
	 // _rawValueInt = (_oriValueFloat << _fractBits); // <= ❌ expression must have integral or enum type
	 _rawValueInt = (_oriValueFloat * (1 << _fractBits));
	cout << "\t* " << _oriValueFloat << " as rawValue (dec): "
				   << _rawValueInt << '\n' // -> 10880 = 42.5 * 256 
	     << "\t* " << _oriValueFloat << " as rawValue (bits): "
		 		   <<  std::bitset<16>(_rawValueInt).to_string().insert(_fractBits, ".")
				   // -> 00101010.10000000, so 42.128? 
				   // Not really: .10000000 here represents 2**-1 => 1/2 or 0.5 OR 128 / 256 👌
		 << '\n' << endl;

	_oriValueFloat = 42.25;
	cout << "\t* original (dec): " << _oriValueFloat << '\n'
		 << "\t* original (bits, casted): "
		 << std::bitset<16>(_oriValueFloat).to_string().insert(_fractBits, ".") // ❌
		 << endl;
	_rawValueInt = (_oriValueFloat * (1 << _fractBits)); // 10816 = 42.25 * 256
	cout << "\t* " << _oriValueFloat << " as rawValue (dec): "
				   << _rawValueInt << '\n' // -> 10816 
	     << "\t* " << _oriValueFloat << " as rawValue (bits): "
		 		   <<  std::bitset<16>(_rawValueInt).to_string().insert(_fractBits, ".")
				   // -> 00101010.01000000, so 42.64?
				   // -> .01000000 represents 2**-2 => 1/4 or 0.25 OR 64 / 256 👌
		 << '\n' << endl;
		 
	// // ########################################################################
	// cout << "Integer or Float rawValue TO an Integer: (✅ both int / float)" 
	// 	 << endl;
	// _rawValueInt = (42 * (1 << _fractBits));
	// cout << "\t* 42 (int) rawValue TO an int: "
	// 	 << (_rawValueInt >> _fractBits) // <=
	// 	 << endl; // -> 42
	// _rawValueInt = (42.42 * (1 << _fractBits));
	// cout << "\t* 42.42 (float) rawValue TO an int: "
	// 	 << (_rawValueInt >> _fractBits) // <=
	// 	 << endl; // -> 42
	// _rawValueInt = (42.99 * (1 << _fractBits));
	// cout << "\t* 42.99 (float) rawValue TO an int: "
	// 	 << (_rawValueInt >> _fractBits) // <=
	// 	 << endl; // -> 42
	// _rawValueInt = (42.999999999999999 * (1 << _fractBits));
	// cout << "\t* 42.999999999999999 (float) rawValue TO an int: "
	// 	 << (_rawValueInt >> _fractBits) // <=
	// 	 << endl; // -> 43!?
	// // ###############
	// cout << "Integer or Float rawValue TO an Integer (alt, ✅ both int / float):" 
	// 	 << endl;
	// _rawValueInt = (42 << _fractBits);
	// cout << "\t* 42 (int) rawValue TO an int (alt): "
	// 	 << (_rawValueInt / (1 << _fractBits)) // <=
	// 	 << endl; // -> 42
	// _rawValueInt = (42.99 * (1 << _fractBits));
	// cout << "\t* 42.99 (float) rawValue TO an int: (alt) "
	// 	 << (_rawValueInt / (1 << _fractBits)) // <=
	// 	 << endl; // -> 42
	// _rawValueInt = (42.999999999999999 * (1 << _fractBits));
	// cout << "\t* 42.999999999999999 (float) rawValue TO an int: "
	// 	 << (_rawValueInt / (1 << _fractBits)) // <=
	// 	 << endl; // -> 43!?
	// // ########################################################################
		
	// cout << "Integer or Float rawValue TO a Float:" 
	// 	 << endl;


	
	// _rawValueInt = (42.42 * (1 << _fractBits));
	// cout << "\t* 42.42 (float) rawValue TO a float (alt): "
	// 	 << static_cast<float>(_rawValueInt) / (1 << _fractBits) // <=
	// 	 << endl; // -> 42.375
	// _rawValueInt = (42.99 * (1 << _fractBits));
	// cout << "\t* 42.99 (float) rawValue TO a float (alt): "
	// 	 << static_cast<float>(_rawValueInt) / (1 << _fractBits) // <=
	// 	 << endl; // -> 42.875
	// _rawValueInt = (42.999999999999999 * (1 << _fractBits));
	// cout << "\t* 42.999999999999999 (float) rawValue TO a float (alt): "
	// 	 << static_cast<float>(_rawValueInt) / (1 << _fractBits) // <=
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
