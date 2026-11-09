/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 23:20:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/09 23:20:40 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("default"), _slotSize(0)
{
	_initSlots();
}

Character::Character(const string &name): _name(name), _slotSize(0)
{
	_initSlots();
}

Character::Character(const Character &src): _name(src._name),
	_slotSize(src._slotSize)
{
	_initSlots();
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

void	Character::_initSlots()
{
	for (int i = 0; i < Character::MAX_SLOTS; i++)
		_slot[i] = NULL;
}

void	Character::_cleanUpSlots()
{
	for (int i = 0; i < _slotSize; i++)
	{
		delete _slot[i];
		_slot[i] = NULL;
	}
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

// - They equip the Materias in the first empty slot they find,
// in the following order: from slot 0 to slot 3.
// - If they try to add a Materia to a full inventory, 
// nothing should happen (but bugs are still forbidden).
void	Character::equip(AMateria *m)
{
	if (_slotSize < Character::MAX_SLOTS)
	{
		for (int i = 0; i < _slotSize; i++)
		{
			if (_slot[i] != NULL)
			{
				_slot[i] = m;
				break ;
			}
		}
		_slotSize++;
	}
}

// - If they try to unequip a non-existent Materia, nothing should happen 
// (but bugs are still forbidden).
// - The unequip() member function must NOT delete the Materia!!

// - Handle the Materias your character leaves "on the floor" as you like.
// Save the addresses before calling unequip(), or anything else, but
// don’t forget that you have to avoid memory leaks.
void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < Character::MAX_SLOTS && _slot[idx] != NULL)
	{
		_slot[idx] = NULL;
		// Uncomplete... What should be done with the unequipped materia?
		_slotSize--;
	}
}

// - If they try to use a non-existent Materia, nothing should happen 
// (but bugs are still forbidden).
// - The use(int, ICharacter&) member function will have to use the Materia at
// the slot[idx], and pass the target parameter to the AMateria::use function.
void 	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < Character::MAX_SLOTS && _slot[idx] != NULL)
		_slot[idx]->use(target);
}
