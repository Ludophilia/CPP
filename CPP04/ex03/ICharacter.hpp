/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 22:47:32 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/05 20:08:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP

# define ICHARACTER_HPP

# include <string>
# include "AMateria.hpp"

using std::string;

// An Interface still needs a virtual destructor to avoid messing up with the
// destruction process of the Derived classes that will be called as ICharacter
// but still need to run their own destructor.
class ICharacter
{
	public:

	virtual const string	&getName() const = 0;
	virtual void			equip(AMateria* m) = 0;
	virtual void 			unequip(int idx) = 0;
	virtual void 			use(int idx, ICharacter &target) = 0;

	virtual ~ICharacter() {}; // virtual ~ICharacter() = default; (c++11)
};

#endif
