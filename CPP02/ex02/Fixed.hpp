/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:13:18 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/15 22:29:15 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:

	Fixed(void);
	~Fixed(void);
	Fixed(const int intVal);
	Fixed(const float floatVal);
	Fixed(const Fixed &src);
	
	int		getRawBits(void) const;
	float	toFloat(void) const;
	int		toInt(void) const;
	void	setRawBits(const int raw);

	Fixed	&operator=(const Fixed &rhs);

	// >, <, >=, <=, ==, and !=

	bool	operator>(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;

	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	
	// +, -, *, and /.

	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;

	
	
	// ++ and -- (pre / post)

	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);
	
	

	// A static member function min that takes two references to fixed-point numbers as
	// parameters, and returns a reference to the smallest one

	// A static member function min that takes two references to constant fixed-point
	// numbers as parameters, and returns a reference to the smallest one.

	// A static member function max that takes two references to fixed-point numbers as
	//parameters, and returns a reference to the greatest one.
 
	// A static member function max that takes two references to constant fixed-point
	// numbers as parameters, and returns a reference to the greatest one.

	private:
	
	static const int	_fbits = 8;
	int					_value;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &rhs);

#endif
