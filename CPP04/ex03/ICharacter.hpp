/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 22:47:32 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/09 23:10:09 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP

# define ICHARACTER_HPP

# include <string>

using std::string;

// # include "AMateria.hpp" // circular dependency ❌
class AMateria; // ✅ circular dependency to AMateria broken with forward 
// declaration. Only possible when pointers are involved it seems?

// An Interface still needs a virtual destructor to avoid messing up with the
// destruction process of the Derived classes that will be called as ICharacter
// but still need to run their own destructors.
class ICharacter
{
	public:

	virtual const string	&getName() const = 0;
	virtual void			equip(AMateria *m) = 0;
	virtual void 			unequip(int idx) = 0;
	virtual void 			use(int idx, ICharacter &target) = 0;

	virtual ~ICharacter() {}; // virtual ~ICharacter() = default; (c++11)
};

#endif
