/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 22:41:44 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/16 23:49:44 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inventory.hpp"

Inventory::Inventory()
	: _size(0)
{
	_init();
}

Inventory::Inventory(const Inventory &src) throw(bad_alloc)
	: _size(0)
{
	_init();
	_clone(src);
}

Inventory::~Inventory()
{
	_cleanup();
}

Inventory	&Inventory::operator=(const Inventory &rhs) throw(bad_alloc)
{
	if (this != &rhs)
	{
		_cleanup();
		_clone(rhs);
	}
	return (*this);
}

void	Inventory::_init()
{
	for (int i = 0; i < Inventory::MAX_SLOTS; i++)
		_slot[i] = NULL;
}

void	Inventory::_clone(const Inventory &src) throw(bad_alloc)
{
	int	i = -1;

	try
	{
		while (++i < Inventory::MAX_SLOTS)
		{
			if (src._slot[i] != NULL)
			{
				_slot[i] = src._slot[i]->clone();
				_size++;
			}
		}
		if (_size != src._size)
			throw bad_alloc();
	}
	catch (const bad_alloc &e)
	{
		cerr << e.what() << endl;
		_cleanup(false, i - 1);
		throw;
	}
}

void	Inventory::_cleanup(bool fwd, int i)
{
	while ((fwd && i < Inventory::MAX_SLOTS) || (!fwd && i >= 0))
	{
		if (_slot[i] != NULL)
		{
			delete _slot[i];
			_slot[i] = NULL;
			_size--;
		}
		i += fwd ? 1: -1;
	}
}

AMateria	*Inventory::get(const string &type) const
{
	for (int i = 0; i < Inventory::MAX_SLOTS; i++)
	{
		if (_slot[i] != NULL && _slot[i]->getType() == type)
			return (_slot[i]);
	}
	return (NULL);
}

void	Inventory::use(int idx, ICharacter &target) const
{
	if (idx >= 0 && idx < Inventory::MAX_SLOTS && _slot[idx] != NULL)
		_slot[idx]->use(target);
	else
		cerr << "the materia at index " << idx << " doesn't exist!" << endl;
}

void	Inventory::add(AMateria *m)
{
	if (m != NULL && _size < Inventory::MAX_SLOTS)
	{
		for (int i = 0; i < Inventory::MAX_SLOTS; i++)
		{
			if (_slot[i] == NULL)
			{
				_slot[i] = m;
				break ;
			}
		}
		_size++;
	}
	else
		cerr << "can't add the new materia identified by: " << m << endl;
}

void	Inventory::remove(int idx)
{
	if (idx >= 0 && idx < Inventory::MAX_SLOTS && _slot[idx] != NULL)
	{
		_slot[idx] = NULL;
		_size--;
	}
	else
		cerr << "can't remove materia at index " << idx << "!" << endl;
}
