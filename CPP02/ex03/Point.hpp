/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:59 by jegerman          #+#    #+#             */
/*   Updated: 2026/09/10 22:30:12 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP

# define POINT_HPP

// #include <functional>
#include <exception>
// #include <iosteam>

// using	std::cout;
// using	std::endl;

#include "Fixed.hpp"


class Point
{
	public:

	Point();
	Point(const Point &src);
	Point(const float x, const float y);
	Point &operator=(const Point &rhs); // = delete is C++ 11 and above.
	~Point();

	class NotImplementedOperator: std::exception 
	{
		virtual const char *what() const throw();
	};

	// anything else useful

	private:

	const Fixed		_x;
	const Fixed		_y;

	// anything else useful
};

#endif
