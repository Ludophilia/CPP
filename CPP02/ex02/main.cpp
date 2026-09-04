/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:04:24 by jegerman          #+#    #+#             */
/*   Updated: 2026/09/04 22:02:11 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int	main(void)
{
	// Fixed			a;
	// Fixed const		b(Fixed(5.05f) * Fixed(2));

	// cout << (Fixed(42) < Fixed(100)) << endl;
	// cout << (Fixed(42) > Fixed(100)) << endl;

	cout << "Addition:" << endl;
	cout << "\t" << (Fixed(0) + Fixed(0)) << endl;
	cout << "\t" << (Fixed(100) + Fixed(100)) << endl;
	cout << "\t" << (Fixed(100.25f) + Fixed(100.75f)) << endl;

	cout << "Substraction:" << endl;
	cout << "\t" << (Fixed(0) - Fixed(0)) << endl;
	cout << "\t" << (Fixed(100) - Fixed(100)) << endl;
	cout << "\t" << (Fixed(100.75f) - Fixed(100)) << endl;
	cout << "\t" << (Fixed(100.75f) - Fixed(101)) << endl;
	cout << "Multiplication:" << endl;

	cout << "\t" << (Fixed(42.125f) * Fixed(0)) << endl;
	cout << "\t" << (Fixed(42.125f) * Fixed(2)) << endl;
	cout << "\t" << (Fixed(42.125f) * Fixed(4)) << endl;
	cout << "\t" << (Fixed(42.125f) * Fixed(-2)) << endl;

	cout << "Division:" << endl;
	cout << "\t" << (Fixed(42.0f) / Fixed(0)) << endl; // !? -8.38861e+06? WTF?
	cout << "\t" << (Fixed(42.0f) / Fixed(2)) << endl;

	// cout << (Fixed(42) + Fixed(1)).toInt() << endl;

	// cout << a << endl;
	// cout << ++a << endl;
	// cout << a << endl;
	// a.setRawBits(0);
	// cout << a++ << endl;
	// cout << a << endl;
	
	// a.setRawBits(0);
	// cout << a << endl;
	// cout << --a << endl;
	// cout << a << endl;
	// a.setRawBits(0);
	// cout << a-- << endl;
	// cout << a << endl;

	// cout << b << endl;
	// cout << Fixed::max( a, b ) << endl;
	return 0;
}

/* Real main, edit cautiously!! Actually... DON'T.*/
// int main()
// {
// 	Fixed 			a;
// 	Fixed const 	b(Fixed(5.05f) * Fixed(2));

// 	cout << a << endl;
// 	cout << ++a << endl;
// 	cout << a << endl;
// 	cout << a++ << endl;
// 	cout << a << endl;

// 	cout << b << endl;

// 	cout << Fixed::max(a, b) << endl;
// 	return (0);
// }
