/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:58:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/12 15:24:57 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// MateriaSource();
// MateriaSource(const MateriaSource &src);
// ~MateriaSource();

// MateriaSource	&operator=(const MateriaSource &rhs);

// Copies the Materia passed as a parameter and stores it in memory so it can
// be cloned later.
//  Like the Character, the MateriaSource can know at most 4 Materias. They
// are not necessarily unique.
void		MateriaSource::learnMateria(AMateria *m)
{
	if (_slotSize < 4)
		_slot[_slotSize++] = m;
}

// Returns a new Materia. The latter is a copy of the Materia previously learned by
// the MateriaSource whose type equals the one passed as parameter.
// Returns 0 if the type is unknown.
AMateria	*MateriaSource::createMateria(const string &type) throw(bad_alloc)
{
	for (int i = 0; i < _slotSize; i++)
	{
		if (_slot[i]->getType() == type)
			return (_slot[i]->clone());
	}
	return (0);
}
