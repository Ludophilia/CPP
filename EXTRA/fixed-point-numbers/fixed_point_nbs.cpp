/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point_nbs.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 22:57:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/09/02 23:03:32 by jegerman         ###   ########.fr       */
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

	// 	- as in 523.7334, 0101.01, 1024(.00), AEF.9, poney.rapide

	// 	- the point is always at the same spot, meaning there's
	// 		- a fixed number of digits for the whole part
	//		- a fixed number of digits for the fractional part
	
	// The point position affect the value of each digit.
	// 		- In a number in base 2 but it works for any base for that matter, 
	//		the bit b0 at the left of the point has a value of b0 * 2^0.
	//			- After the point to the right, the bit b-1 has a value of  b-1 * 2^-1
	//			- After the point to the left, the bit b0 has a value of  b0 * 2^0
	//      	- The further we go to the left, the higher the power of two (0, 1, 2...), and
	//      	conversely to the right (-1, -2)...

	// The problem NOW is how we express that in code...

	// ==	An integer... to store the fixed point number.
	// == 	A coefficient 2^N with N > 0 to shift (2^k * 2^N -> 2^(k+N)...) 
	//			the bits of the original value, of N bits. That way, 
	//      	the fractional part of the original value will be SCALED
	//			to fit on the first N bits or the first 2^N values. Some loss of
	//			precision is expected however depending on the number of bits 
	//			allocated to each part...
	// ==	Getting Back to the original number 
	
	// That way:

	//		# 0.125 (2^-3) will be 32 (2^5 or 0.125 * 256) if we choose to 
	//     scale the fractional part to fit the first 8 bits (2**8 => 256)...
	//		   - 0000000000100000 is (1 * 2^5) or 32. But it should be read as
	//		   00000000.00100000 or (1 * 2^-3) or 1/8 or 0.125 ✅.	
	//		# 0.5 will be 128 (0.5 * 256)...
	//		   - 0000000010000000 is (1 * 2^7) or 32. But it should be read as
	//		   00000000.10000000 or (1 * 2^-1) or 1/2 or 0.5 ✅.	
	
	// The whole part will be affected as well:

	//      # 1 will be 256 (1 * 256) if we choose to 'encode' the fractional part
	// 		on the first 8 bits (2**8 => 256)
	//		   - 0000000100000000 is (1 * 2^8) or 256. But it should be read as
	//		   00000001.00000000 or (1 * 2^0) or 1 or... 😯 (1 << 8) 
	//		# 42 will be 10752 (42 * 256)...
	//		   - 0010101000000000 is (2^9 + 2^11 + 2^13) or 10752
	//		   - OR 00101010.00000000 (2^1 + 2^3 + 2^5) as a fixed with 8 bits 
	//         for the fractional part. Note that 9 = 1 + 8, 11 = 3 + 8, 13 = 5 + 8.
	//         Yeah, that 8 bits left shift or * 256 or * 2^8 again...
	//      # 0 will stay 0 (0 * 256)... 

	// ########################################################################

	// Here's some examples of fixed point numbers.

	// A 32 bits integer with 24 spots for the whole part + 8 for the fractional. 

	const int		_fractBits = 8; // 8 default
	int				_oriValueInt;
	float			_oriValueFloat;
	float			_convValueFloat;
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
		 << std::bitset<16>(_oriValueInt).to_string().insert(16, ".")
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
		 << std::bitset<16>(_oriValueFloat).to_string().insert(16, ".") // ❌
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
		 << std::bitset<16>(_oriValueFloat).to_string().insert(16, ".") // ❌
		 << endl;
	_rawValueInt = (_oriValueFloat * (1 << _fractBits)); // 10816 = 42.25 * 256
	cout << "\t* " << _oriValueFloat << " as rawValue (dec): "
				   << _rawValueInt << '\n' // -> 10816 
	     << "\t* " << _oriValueFloat << " as rawValue (bits): "
		 		   <<  std::bitset<16>(_rawValueInt).to_string().insert(_fractBits, ".")
					// -> 00101010.01000000, so 42.64?
				   // -> .01000000 represents 2**-2 => 1/4 or 0.25 OR 64 / 256 👌
		 << '\n' << endl;
		 
	// ########################################################################

	cout << "Integer or Float rawValue TO an Integer:"
		 << endl;
	
	_oriValueFloat = 42;
	_rawValueInt = (_oriValueFloat * (1 << _fractBits));
	_convValueFloat = ALT? (_rawValueInt / (1 << _fractBits)) 
					: (_rawValueInt >> _fractBits);// <=
	cout << "\t* " << _oriValueFloat
				   << " (int) rawValue TO an int: "
				   << _convValueFloat << endl; // -> 42

	_oriValueFloat = 42.42;
	_rawValueInt = (_oriValueFloat * (1 << _fractBits));
	_convValueFloat = ALT? (_rawValueInt / (1 << _fractBits)) 
					: (_rawValueInt >> _fractBits);// <=
	cout << "\t* " << _oriValueFloat
				   << " (float) rawValue TO an int: "
				   << _convValueFloat << endl; // -> 42

	_oriValueFloat = 42.99;
	_rawValueInt = (_oriValueFloat * (1 << _fractBits));
	_convValueFloat = ALT? (_rawValueInt / (1 << _fractBits)) 
					: (_rawValueInt >> _fractBits);// <=
	cout << "\t* " << _oriValueFloat
				   << " (float) rawValue TO an int: "
				   << _convValueFloat << endl; // -> 42

	_oriValueFloat = 42.999999999999999;
	_rawValueInt = (_oriValueFloat * (1 << _fractBits));
	_convValueFloat = ALT? (_rawValueInt / (1 << _fractBits)) 
					: (_rawValueInt >> _fractBits);// <=
	cout << "\t* " << _oriValueFloat
				   << " (float) rawValue TO an int: "
				   << _convValueFloat << '\n' << endl; // -> 43!?

	// // ########################################################################
		
	cout << "Integer or Float rawValue TO a Float:" 
		 << endl;
	
	_oriValueFloat = 42;
	_rawValueInt = (_oriValueFloat * (1 << _fractBits));
	_convValueFloat = static_cast<float>(_rawValueInt) / (1 << _fractBits);// <=
	cout << "\t* " << _oriValueFloat
				   << " (int) rawValue TO a float: "
				   << _convValueFloat << endl; // -> 42

	_oriValueFloat = 42.42;
	_rawValueInt = (_oriValueFloat * (1 << _fractBits));
	// _convValueFloat = static_cast<float>((_rawValueInt >> _fractBits)); // ❌
	_convValueFloat = static_cast<float>(_rawValueInt) / (1 << _fractBits);// <=
	cout << "\t* " << _oriValueFloat
				   << " (float) rawValue TO a float: "
				   << _convValueFloat << endl; // -> 42.418

	_oriValueFloat = 42.99;
	_rawValueInt = (_oriValueFloat * (1 << _fractBits));
	_convValueFloat = static_cast<float>(_rawValueInt) / (1 << _fractBits);// <=
	cout << "\t* " << _oriValueFloat
				   << " (float) rawValue TO a float: "
				   << _convValueFloat << endl; // -> 42.9883

	_oriValueFloat = 42.999999999999999;
	_rawValueInt = (_oriValueFloat * (1 << _fractBits));
	_convValueFloat = static_cast<float>(_rawValueInt) / (1 << _fractBits);// <=
	cout << "\t* " << _oriValueFloat
				   << " (float) rawValue TO a float: "
				   << _convValueFloat << '\n' << endl; // -> 43!?

	// #######################################################################

	// (What I did in March 2026, improved...)
	
	cout << "Encoding the original value 3.25 TO fixed number with 16 bits"
	" for the fractional part" << endl;
	
	// cout << "\t*  3.25 -> "
			    // << (3.25 << 16) << endl; // ❌ expression must have integral or enum type
	cout << "\t* 3.25 fixed -> "
				<< (3.25 * (1 << 16)) << '\n' << endl; // ✅ 3.25 fixed -> 212992

	cout << "Converting the fixed number 212992 BACK to its original value"
	" 3.25" << endl;
	
	cout << "\t* 3 int (integer division) -> "
				<< (212992 / (1 << 16)) << endl; // ❌ 3 int -> 3
	cout << "\t* 3 int (right shifting, lost the fractional part) -> "
				<< (212992 >> 16) << endl; // ❌ 3 int -> 3
	cout << "\t* 3.25 (float division) -> "
				<< (212992) / (float)(1 << 16) << '\n' << endl;// ✅ 3 int -> 3

	cout << "Converting the fixed number 212992 BACK to its original value "
	"3.25 WHILE isolating one part or the other..." << endl;

	cout << "\t* Isolating the fractional part (0.25) -> "
			<< (212992 & 0xFFFF) / (float)(1 << 16) << endl; // 0.25 
	cout << "\t* Isolating the fractional part (0.25) -> "
			<< (212992 & ((1 << 16) - 1)) / (float)(1 << 16) << endl; // 0.25 
	//  === That example with 0.25 is interesting. We mask the bits 
	// representing the whole part before converting back to the original 
	// number. Could be useful...

	// cout << "\t* Isolating the whole part (3) -> "
	//		<< (212992 & ~(1 << 16)) << endl; // ❌ Oops... 😅
	cout << "\t* Isolating the whole part (3) -> " 
			<< (212992 & ~((1 << 16) - 1)) / (float)(1 << 16) << endl; // 3
	//  === Similarly, by inversing the mask's bits, we can o
	return 0;
}
