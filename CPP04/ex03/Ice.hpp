/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:20:06 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/05 23:10:07 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP

# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

using std::cout;
using std::endl;

class Ice: public AMateria
{
	public:

	Ice();
	Ice(const Ice &src);
	~Ice();

	Ice	&operator=(const Ice &rhs);

	void		use(ICharacter& target) const;
	AMateria	*clone() const;
};

#endif
