/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:15:50 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/25 23:11:30 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed		a;
	Fixed		b(a); // Copy constructor. Eq to Fixed b = a;
	Fixed 		c;

	c = b; // Copy assignment operator. Think of it as c.operator=(b)...
	cout << a.getRawBits() << endl;
	cout << b.getRawBits() << endl;
	cout << c.getRawBits() << endl;
	return (0);
}
