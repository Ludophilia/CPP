/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 19:21:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/15 01:26:59 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	// Fixed			a;
	// Fixed const		b(Fixed(5.05f) * Fixed(2));

	// std::cout << (Fixed(42) < Fixed(100)) << std::endl;
	// std::cout << (Fixed(42) > Fixed(100)) << std::endl;

	std::cout << (Fixed(100) + Fixed(100)) << std::endl;
	std::cout << (Fixed(100) - Fixed(100)) << std::endl;
	std::cout << (Fixed(42.2f) * Fixed(2)) << std::endl;
	std::cout << (Fixed(42.0f) / Fixed(2)) << std::endl;

	// std::cout << (Fixed(42) + Fixed(1)).toInt() << std::endl;

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
