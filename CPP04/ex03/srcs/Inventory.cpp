/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 22:41:44 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/12 20:22:37 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inventory.hpp"

Inventory::Inventory()
	: _size(0)
{
	_init();
}

Inventory::Inventory(const Inventory &src) throw(bad_alloc)
	: _size(src._size) 
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
		_size = rhs._size;
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
		while (++i < src._size)
			_slot[i] = src._slot[i]->clone();
	}
	catch (const bad_alloc &e)
	{
		cerr << e.what() << endl;
		_cleanup(false, i - 1);
		throw;
	}
}

void	Inventory::_cleanup(bool fwd = true, int i = 0)
{
	while ((fwd && i < _size) || (!fwd && i >= 0))
	{
		delete _slot[i];
		_slot[i] = NULL;
		i += fwd ? 1: -1;
	}
}

// 12/11 - _size update methods required
