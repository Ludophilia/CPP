/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:13:18 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/13 01:39:46 by jegerman         ###   ########.fr       */
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
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &rhs);
	
	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	private:
	
	static const int	_fbits = 8;
	int					_value;
};

#endif
