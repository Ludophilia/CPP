/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:13:18 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/25 22:27:17 by jegerman         ###   ########.fr       */
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
	~Fixed();
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &rhs);
	
	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	private:
	
	static const int	_fbits = 8;
	int					_rvalue;
};

#endif
