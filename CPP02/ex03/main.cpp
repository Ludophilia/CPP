/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:04:24 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/07 23:31:33 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	bool	bsp(Point const, Point const, Point const, Point const);

	cout << "bsp(inside) => " 
		 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(3, 2))
		 << endl;
	cout << "bsp(edge) => " 
		 << bsp(Point(0, 4), Point(0, 0), Point(6, 0), Point(0, 2))
		 << endl;
	cout << "bsp(outside) => "
		 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(5, 2))
		 << endl;
	// More to come
	return (0);
}
