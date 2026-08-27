/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:13:18 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/27 19:27:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>
# include <cmath>

using std::ostream;

using std::cout;
using std::endl;

class Fixed
{
	public:

	Fixed();
	Fixed(const Fixed &src);
	Fixed(const int intVal);
	Fixed(const float floatVal);
	~Fixed();

	Fixed	&operator=(const Fixed &rhs);

	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(const int raw);
 
	private:
	
	static const int	_fractBits = 8;
	int					_rawValue;
};

ostream	&operator<<(ostream &out, const Fixed &rhs);

#endif
