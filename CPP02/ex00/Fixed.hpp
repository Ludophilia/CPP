/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:13:18 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/26 21:42:52 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

using std::cout;
using std::endl;

class Fixed
{
	public:

	Fixed();
	Fixed(const Fixed &src);
	~Fixed();
	
	Fixed	&operator=(const Fixed &rhs);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	private:
	
	static const int	_fractBits = 8;
	int					_rawValue;
};

#endif
