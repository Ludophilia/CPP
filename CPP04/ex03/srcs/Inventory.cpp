/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 22:41:44 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/10 23:46:40 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inventory.hpp"

Inventory::Inventory(): _size(0)
{
	for (int i = 0; i < Inventory::MAX_SLOTS; i++)
		_slot[i] = NULL;
}

Inventory::Inventory(const Inventory &src): _size(src._size)
{
	try
		{
			while (++i < src._size)
				_slot[i] = rhs._slot[i]->clone();
		}
		catch (const bad_alloc &e)
		{
			cerr << e.what() << endl;
			while (--i >= 0)
				delete _slot[i];
			throw;
		}
	// *this = src;
}

void	Inventory::cleanUp()
{
	for (int i = 0; i < _size; i++)
	{
		delete _slot[i];
		_slot[i] = NULL;
	}
}

Inventory::~Inventory()
{
	cleanUp();
}

Inventory	&Inventory::operator=(const Inventory &rhs)
{
	if (this != &rhs)
	{
		int i = -1;

		// And what if there are already some materias in place? This won't work.
		// unless...

		cleanUp();

		// duplicate code :/

		
		try
		{
			_size = rhs._size;
			while (++i < rhs._size)
				_slot[i] = rhs._slot[i]->clone();
		}
		catch (const bad_alloc &e)
		{
			cerr << e.what() << endl;
			while (--i >= 0)
				delete _slot[i];
			throw;
		}
	}
	return (*this);
}
