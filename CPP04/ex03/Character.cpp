/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 23:20:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/06 23:27:15 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("default"), _slotSize(0) {}

Character::Character(const string &name): _name(name), _slotSize(0) {}

Character::Character(const Character &src): _name(src._name),
	_slotSize(src._slotSize)
{
	_copySourceSlots(src);
}

Character::~Character()
{
	_cleanUpSlots();
}

Character	&Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		_cleanUpSlots();
		_name = rhs._name;
		_slotSize = rhs._slotSize;
		_copySourceSlots(rhs);
	}
	return (*this);
}

void	Character::_cleanUpSlots() const
{
	for (int i = 0; i < _slotSize; i++)
		delete _slot[i];
}

void	Character::_copySourceSlots(const Character &src)
{
	int	i = -1;

	try
	{
		while (++i < _slotSize)
			_slot[i] = src._slot[i]->clone();
	}
	catch (const std::bad_alloc &e)
	{
		cerr << e.what() << endl;
		while (--i >= 0)
			delete _slot[i];
		throw;
	}
}

const string	&Character::getName() const
{
	return (_name);
}

// They equip the Materias in the first empty slot they find,
// in the following order: from slot 0 to slot 3.
//  If they try to add a Materia to a full inventory, or use/unequip
// a non-existent Materia, nothing should happen (but bugs
// are still forbidden).
// void			equip(AMateria *m);

// The unequip() member function must NOT delete the Materia
// void 			unequip(int idx);

// void 			use(int idx, ICharacter &target);
