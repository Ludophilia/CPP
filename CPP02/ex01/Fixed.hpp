/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:13:18 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/14 01:00:27 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:

	Fixed(void);
	~Fixed(void);
	Fixed(const int intVal);
	Fixed(const float floatVal);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &rhs);

	int				getRawBits(void) const;
	void			setRawBits(const int raw);
	float			toFloat(void) const;
	int				toInt(void) const;
 
	private:
	
	static const int	_fbits = 8;
	int					_value;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &rhs);

#endif
