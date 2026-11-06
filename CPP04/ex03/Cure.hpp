/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:20:03 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/05 23:46:54 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP

# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

using std::cout;
using std::endl;

class Cure: public AMateria
{
	public:

	Cure();
	Cure(const Cure &src);
	~Cure();

	Cure	&operator=(const Cure &rhs);

	void		use(ICharacter &target) const;
	AMateria	*clone() const;
};

#endif
