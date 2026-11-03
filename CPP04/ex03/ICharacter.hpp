/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 22:47:32 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/03 23:37:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP

# define ICHARACTER_HPP

# include <string>
# include "AMateria.hpp"

using std::string;

// An Interface still needs a virtual destructor to correctly perform its role
// as a Base class in the destruction process. The derived classes will
// be called as ICharacter after all...
class ICharacter
{
	public:

	virtual ~ICharacter() {};

	virtual const string	&getName() const = 0;
	virtual void			equip(AMateria* m) = 0;
	virtual void 			unequip(int idx) = 0;
	virtual void 			use(int idx, ICharacter& target) = 0;
};

#endif
