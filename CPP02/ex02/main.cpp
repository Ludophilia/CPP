/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:04:24 by jegerman          #+#    #+#             */
/*   Updated: 2026/09/07 22:42:14 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int	main(void)
{
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

	cout << "Superior and Inferior to (>, <):" << endl;

	cout << "\t" << "0 > 0 -> " << (Fixed(0) > Fixed(0)) << endl;
	cout << "\t" << "42 > 100 -> " << (Fixed(42.1f) > Fixed(100)) << endl;
	cout << "\t" << "42.1 > 100 -> " << (Fixed(42.1f) > Fixed(100)) << endl;
	cout << "\t" << "99.9 > 100 -> " << (Fixed(99.9f) > Fixed(100)) << endl;

	cout << "Superior and Inferior to (>, <):" << endl;

	cout << "\t" << "0 < 0 -> " << (Fixed(0) < Fixed(0)) << endl;
	cout << "\t" << "42 < 100 -> " << (Fixed(42.1f) < Fixed(100)) << endl;
	cout << "\t" << "42.1 < 100 -> " << (Fixed(42.1f) < Fixed(100)) << endl;
	cout << "\t" << "99.9 < 100 -> " << (Fixed(99.9f) < Fixed(100)) << endl;

	cout << "Superior or equal and Inferior or equal to (>=, <=):" << endl;

	cout << "\t" << "0 >= 0 -> " << (Fixed(0) >= Fixed(0)) << endl;
	cout << "\t" << "42 >= 100 -> " << (Fixed(42.1f) >= Fixed(100)) << endl;
	cout << "\t" << "42.1 >= 100 -> " << (Fixed(42.1f) >= Fixed(100)) << endl;
	cout << "\t" << "99.9 >= 100 -> " << (Fixed(99.9f) >= Fixed(100)) << endl;

	cout << "Superior or equal and Inferior or equal to (>=, <=):" << endl;

	cout << "\t" << "0 <= 0 -> " << (Fixed(0) <= Fixed(0)) << endl;
	cout << "\t" << "42 <= 100 -> " << (Fixed(42.1f) <= Fixed(100)) << endl;
	cout << "\t" << "42.1 <= 100 -> " << (Fixed(42.1f) <= Fixed(100)) << endl;
	cout << "\t" << "99.9 <= 100 -> " << (Fixed(99.9f) <= Fixed(100)) << endl;

	cout << "Equal and different to (==, !=):" << endl;

	cout << "\t" << "0 == 0 -> " << (Fixed(0) == Fixed(0)) << endl;
	cout << "\t" << "42 == 100 -> " << (Fixed(42.1f) == Fixed(100)) << endl;
	cout << "\t" << "42.1 == 100 -> " << (Fixed(42.1f) == Fixed(100)) << endl;
	cout << "\t" << "99.9 == 100 -> " << (Fixed(99.9f) == Fixed(100)) << endl;

	cout << "Equal and different to (==, !=):" << endl;

	cout << "\t" << "0 != 0 -> " << (Fixed(0) != Fixed(0)) << endl;
	cout << "\t" << "42 != 100 -> " << (Fixed(42.1f) != Fixed(100)) << endl;
	cout << "\t" << "42.1 != 100 -> " << (Fixed(42.1f) != Fixed(100)) << endl;
	cout << "\t" << "99.9 != 100 -> " << (Fixed(99.9f) != Fixed(100)) << endl;
	
	Fixed	a = 42;
	cout << "Postfix Increment and decrement (var++, var--):" << endl;

	cout << "\tbefore: " << a << ", \"during\" var++: " << a++ << ", after: " << a << endl;
	cout << "\tbefore: " << a << ", \"during\" var--: " << a-- << ", after: " << a << endl;

	cout << "Prefix Increment (++var):" << endl;

	cout << "\tbefore: " << a << ", \"during\" ++var: " << ++a << ", after: " << a << endl;
	cout << "\tbefore: " << a << ", \"during\" --var: " << --a << ", after: " << a << endl;

	// Fixed const		b(Fixed(5.05f) * Fixed(2));

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
