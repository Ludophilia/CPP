/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:32:59 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/07 23:19:46 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP

# define POINT_HPP

# include <exception>
# include "Fixed.hpp"

class Point
{
	public:

	Point();
	Point(const Point &src);
	Point(const float x, const float y);
	~Point();

	Point &operator=(const Point &rhs); // = delete is C++ 11 and above.

	class InvalidOperation: std::exception 
	{
		virtual const char *what() const throw();
	};

	float fgetX() const;
	float fgetY() const;

	private:

	const Fixed		_x;
	const Fixed		_y;

	// Point &operator=(const Point &rhs); // Can't set the copy assignment 
	// operator as private as the assignment requires it to be public...
};

typedef Point Vector;

#endif
