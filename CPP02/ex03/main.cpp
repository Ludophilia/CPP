/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:04:24 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/08 22:22:49 by jegerman         ###   ########.fr       */
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

	cout << "For A(3, 4), B(0, 0), C(6, 0): (an isosceles triangle)" << endl;
	cout << "\t* bsp with point(3, 2) (inside) => " 
		 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(3, 2))
		 << endl;
	cout << "\t* bsp with point(0.5, 0.5) close to AB (inside) => " 
		 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(0.5, 0.5))
		 << endl;
	cout << "\t* bsp with point(0.5, 0.5) even closer to AB (inside) => " 
		 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(0.25, 0.25))
		 << endl;
	cout << "\t* bsp with point(3, 0.5) slightly above BC (inside) => " 
		 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(3, 0.5))
		 << endl;
	cout << "\t* bsp with point(3, 0) on BC (edge) => " 
		 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(3, 0))
		 << endl;
	cout << "\t* bsp with point(3, 4) on A (vertex) => " 
		 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(3, 4))
		 << endl;
	cout << "\t* bsp with point(0, 0) on B (vertex) => " 
		 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(0, 0))
		 << endl;
	cout << "\t* bsp with point(3, -0.5) slightly below BC (outside) => " 
		 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(3, -0.5))
		 << endl;
	cout << "\t* bsp with point(-42, 42) (outside) => " 
		 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(-42, 42))
		 << endl;

	cout << "For A(-1, 0), B(0, 0), C(3, 0) (a degenerate triangle):" << endl;
	cout << "\t* bsp with point(1, 0) (edge) => "
		 << bsp(Point(-1, 0), Point(0, 0), Point(3, 0), Point(1, 0))
		 << endl;
	cout << "\t* bsp with point(0, 1) above B (outside) => "
		 << bsp(Point(-1, 0), Point(0, 0), Point(3, 0), Point(0, 1))
		 << endl;
	cout << "\t* bsp with point(0, -1) below B (outside) => "
		 << bsp(Point(-1, 0), Point(0, 0), Point(3, 0), Point(0, -1))
		 << endl;
	cout << "\t* bsp with point(0, 0) on B (vertex) => "
		 << bsp(Point(-1, 0), Point(0, 0), Point(3, 0), Point(0, 0))
		 << endl;
	cout << "\t* bsp with point(3, 0) on C (vertex) => "
		 << bsp(Point(-1, 0), Point(0, 0), Point(3, 0), Point(3, 0))
		 << endl;
	// Negative coordinates

	cout << "For A(-3, -2), B(-8, -4), C(-1, 0) (a scalene triangle "
	"with negative coords):" << endl;
	cout << "\t* bsp with point(-4, -2) (inside) => " 
		 << bsp(Point(-3, -2), Point(-8, -4), Point(-1, 0), Point(-4, -2))
		 << endl;
	// Triangle as a straight line => O
		 
	// cout << "bsp(edge) => " 
	// 	 << bsp(Point(0, 4), Point(0, 0), Point(6, 0), Point(0, 2))
	// 	 << endl;
	// cout << "bsp(outside) => "
	// 	 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(5, 2))
	// 	 << endl;

	// cout << "bsp(outside) => "
	// 	 << bsp(Point(3, 4), Point(0, 0), Point(6, 0), Point(4, 6))
	// 	 << endl;

	// cout << "bsp(vertex) => "
	// 	 << bsp(Point(3, 4), Point(3, 4), Point(6, 0), Point(4, 6))
	// 	 << endl;
	// More to come
	return (0);
}
