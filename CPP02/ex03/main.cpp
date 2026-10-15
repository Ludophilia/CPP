/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:04:24 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/15 20:15:35 by jegerman         ###   ########.fr       */
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

	cout << "For A(6, 0), B(0, 0), C(3, 4): (an isosceles triangle T1)" << endl;
	cout << "\t* bsp with point(3, 2) (inside) => " 
		 << bsp(Point(6, 0), Point(0, 0), Point(3, 4), Point(3, 2))
		 << endl;
	cout << "\t* bsp with point(3, 0) (edge AB) => " 
		 << bsp(Point(6, 0), Point(0, 0), Point(3, 4), Point(3, 0))
		 << endl;
	cout << "\t* bsp with point(3, -0.5) (outside, below AB) => " 
		 << bsp(Point(6, 0), Point(0, 0), Point(3, 4), Point(3, -0.5))
		 << endl;
	cout << "\t* bsp with point(3, 0.5) (inside, above AB) => " 
		 << bsp(Point(6, 0), Point(0, 0), Point(3, 4), Point(3, 0.5))
		 << endl;
	cout << "\t* bsp with point(6, 0) (vertex, on A) => " 
		 << bsp(Point(6, 0), Point(0, 0), Point(3, 4), Point(6, 0))
		 << endl;
	cout << "\t* bsp with point(-42, 42) (outside) => " 
		 << bsp(Point(6, 0), Point(0, 0), Point(3, 4), Point(-42, 42))
		 << endl << endl;
		 
	cout << "For A(0, 0), B(6, 0), C(3, 4): (T2: T1 with A and B swapped)" << endl;
	cout << "\t* bsp with point(3, 2) (inside) => " 
		 << bsp(Point(0, 0), Point(6, 0), Point(3, 4), Point(3, 2))
		 << endl;
	cout << "\t* bsp with point(3, 0) (edge BA) => " 
		 << bsp(Point(0, 0), Point(6, 0), Point(3, 4), Point(3, 0))
		 << endl;
	cout << "\t* bsp with point(3, -0.5) (outside, below BA) => " 
		 << bsp(Point(0, 0), Point(6, 0), Point(3, 4), Point(3, -0.5))
		 << endl;
	cout << "\t* bsp with point(3, 0.5) (inside, above BA) => " 
		 << bsp(Point(0, 0), Point(6, 0), Point(3, 4), Point(3, 0.5))
		 << endl;
	cout << "\t* bsp with point(6, 0) (vertex, on B) => " 
		 << bsp(Point(0, 0), Point(6, 0), Point(3, 4), Point(6, 0))
		 << endl;
	cout << "\t* bsp with point(-42, 42) (outside) => " 
		 << bsp(Point(0, 0), Point(6, 0), Point(3, 4), Point(-42, 42))
		 << endl << endl;

	cout << "For A(3, 4), B(6, 0), C(0, 0): (T3: T2 with A and C swapped)" << endl;
	cout << "\t* bsp with point(3, 2) (inside) => "
		 << bsp(Point(3, 4), Point(6, 0), Point(0, 0), Point(3, 2))
		 << endl;
	cout << "\t* bsp with point(3, 0) (edge BC) => " 
		 << bsp(Point(3, 4), Point(6, 0), Point(0, 0), Point(3, 0))
		 << endl;
	cout << "\t* bsp with point(3, -0.5) (outside, below BC) => " 
		 << bsp(Point(3, 4), Point(6, 0), Point(0, 0), Point(3, -0.5))
		 << endl;
	cout << "\t* bsp with point(3, 0.5) (inside, above BC) => " 
		 << bsp(Point(3, 4), Point(6, 0), Point(0, 0), Point(3, 0.5))
		 << endl;
	cout << "\t* bsp with point(6, 0) (vertex, on B) => " 
		 << bsp(Point(3, 4), Point(6, 0), Point(0, 0), Point(6, 0))
		 << endl;
	cout << "\t* bsp with point(-42, 42) (outside) => " 
		 << bsp(Point(3, 4), Point(6, 0), Point(0, 0), Point(-42, 42))
		 << endl << endl;

	cout << "For A(0, 0), B(3, 4), C(6, 0): (T4: T2 with C and B swapped)" << endl;
	cout << "\t* bsp with point(3, 2) (inside) => " 
		 << bsp(Point(0, 0), Point(3, 4), Point(6, 0), Point(3, 2))
		 << endl;
	cout << "\t* bsp with point(3, 0) (edge BA) => " 
		 << bsp(Point(0, 0), Point(3, 4), Point(6, 0), Point(3, 0))
		 << endl;
	cout << "\t* bsp with point(3, -0.5) (outside, below BA) => " 
		 << bsp(Point(0, 0), Point(3, 4), Point(6, 0), Point(3, -0.5))
		 << endl;
	cout << "\t* bsp with point(3, 0.5) (inside, above BA) => " 
		 << bsp(Point(0, 0), Point(3, 4), Point(6, 0), Point(3, 0.5))
		 << endl;
	cout << "\t* bsp with point(6, 0) (vertex, on C) => " 
		 << bsp(Point(0, 0), Point(3, 4), Point(6, 0), Point(6, 0))
		 << endl;
	cout << "\t* bsp with point(-42, 42) (outside) => " 
		 << bsp(Point(0, 0), Point(3, 4), Point(6, 0), Point(-42, 42))
		 << endl << endl;
	
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
	cout << "\t* bsp with point(-42, 42) (outside) => " 
		 << bsp(Point(-1, 0), Point(0, 0), Point(3, 0), Point(-42, 42))
		 << endl << endl;

	cout << "For A(-1, 0), B(0, 0), C(3, 0) (same degenerate triangle, AB swapped):" << endl;
	cout << "\t* bsp with point(1, 0) (edge) => "
		 << bsp(Point(0, 0), Point(-1, 0), Point(3, 0), Point(1, 0))
		 << endl;
	cout << "\t* bsp with point(0, 1) above B (outside) => "
		 << bsp(Point(0, 0), Point(-1, 0), Point(3, 0), Point(0, 1))
		 << endl;
	cout << "\t* bsp with point(0, -1) below B (outside) => "
		 << bsp(Point(0, 0), Point(-1, 0), Point(3, 0), Point(0, -1))
		 << endl;
	cout << "\t* bsp with point(0, 0) on B (vertex) => "
		 << bsp(Point(0, 0), Point(-1, 0), Point(3, 0), Point(0, 0))
		 << endl;
	cout << "\t* bsp with point(3, 0) on C (vertex) => "
		 << bsp(Point(0, 0), Point(-1, 0), Point(3, 0), Point(3, 0))
		 << endl;
	cout << "\t* bsp with point(-42, 42) (outside) => " 
		 << bsp(Point(0, 0), Point(-1, 0), Point(3, 0), Point(-42, 42))
		 << endl << endl;

	cout << "For A(-3, -2), B(-8, -4), C(-1, 0) (a scalene triangle "
	"with negative coords):" << endl;
	cout << "\t* bsp with point(-4, -2) (inside) => " 
		 << bsp(Point(-3, -2), Point(-8, -4), Point(-1, 0), Point(-4, -2))
		 << endl;
	cout << "\t* bsp with point(-1.5, -1) (edge, on AC) => " 
		 << bsp(Point(-3, -2), Point(-8, -4), Point(-1, 0), Point(-1.5, -1))
		 << endl;
	cout << "\t* bsp with point(-2, -1) (outside, on the right of AC) => " 
		 << bsp(Point(-3, -2), Point(-8, -4), Point(-1, 0), Point(-2, -1))
		 << endl;
	cout << "\t* bsp with point(-2.5, -1) (inside, on the left of AC) => " 
		 << bsp(Point(-3, -2), Point(-8, -4), Point(-1, 0), Point(-2.5, -1))
		 << endl;
	cout << "\t* bsp with point(-8, -4) (edge, on B) => " 
		 << bsp(Point(-3, -2), Point(-8, -4), Point(-1, 0), Point(-8, -4))
		 << endl;
	cout << "\t* bsp with point(-42, 42) (outside) => " 
		 << bsp(Point(-3, -2), Point(-8, -4), Point(-1, 0), Point(-42, 42))
		 << endl << endl;

	cout << "For A(-8, -4), B(-3, -2), C(-1, 0) (same scalene triangle, "
	"A and B swapped):" << endl;
	cout << "\t* bsp with point(-4, -2) (inside) => " 
		 << bsp(Point(-8, -4), Point(-3, -2), Point(-1, 0), Point(-4, -2))
		 << endl;
	cout << "\t* bsp with point(-1.5, -1) (edge, on AC) => " 
		 << bsp(Point(-8, -4), Point(-3, -2), Point(-1, 0), Point(-1.5, -1))
		 << endl;
	cout << "\t* bsp with point(-2, -1) (outside, on the right of AC) => " 
		 << bsp(Point(-8, -4), Point(-3, -2), Point(-1, 0), Point(-2, -1))
		 << endl;
	cout << "\t* bsp with point(-2.5, -1) (inside, on the left of AC) => " 
		 << bsp(Point(-8, -4), Point(-3, -2), Point(-1, 0), Point(-2.5, -1))
		 << endl;
	cout << "\t* bsp with point(-8, -4) (edge, on B) => " 
		 << bsp(Point(-8, -4), Point(-3, -2), Point(-1, 0), Point(-8, -4))
		 << endl;
	cout << "\t* bsp with point(-42, 42) (outside) => " 
		 << bsp(Point(-8, -4), Point(-3, -2), Point(-1, 0), Point(-42, 42))
		 << endl;
	return (0);
}
