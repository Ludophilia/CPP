/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 23:20:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/12 17:00:29 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
	: _name("default"), _inventory() {}

Character::Character(const string &name)
	: _name(name), _inventory() {}

Character::Character(const Character &src) throw(bad_alloc)
	: _name(src._name), _inventory(src._inventory) {}

Character::~Character()
{
	// Does it call Inventory destructor? Of course It does but let's be
	// sure of that...
}

Character	&Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_inventory = rhs._inventory;
	}
	return (*this);
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

// - ❌ Handle the Materias your character leaves "on the floor" as you like.
// Save the addresses before calling unequip(), or anything else, but
// don’t forget that you have to avoid memory leaks.
void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < Character::MAX_SLOTS && _slot[idx] != NULL)
	{
		_slot[idx] = NULL;
		// ❌ Uncomplete... What should be done with the unequipped materia?
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
