/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 23:20:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/12 21:43:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
	: _name("default"), _inventory() {}

Character::Character(const string &name)
	: _name(name), _inventory() {}

Character::Character(const Character &src) throw(bad_alloc)
	: _name(src._name), _inventory(src._inventory) {}

Character::~Character() {}

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

void	Character::equip(AMateria *m)
{
	_inventory.add(m);
}

void	Character::unequip(int idx)
{
	_inventory.remove(idx);
}

void 	Character::use(int idx, ICharacter &target)
{
	_inventory.use(idx, target);
}
