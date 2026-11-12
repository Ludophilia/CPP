/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 22:28:47 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/12 16:49:13 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVENTORY_HPP

# define INVENTORY_HPP

#include <iostream>
#include "AMateria.hpp"

// class AMateria;

using std::cerr;
using std::endl;
using std::bad_alloc;

class Inventory
{
	public:

	Inventory();
	Inventory(const Inventory &src) throw(bad_alloc);
	~Inventory();

	Inventory &operator=(const Inventory &rhs) throw(bad_alloc);

	// AMateria				*getSlots();
	// int					getSize();
	// int					setSize();

	void				cleanUp(bool fwd, int i); // private?

	private:

	static const int	MAX_SLOTS = 4;
	
	AMateria			*_slot[MAX_SLOTS];
	int					_size;

	void 				_cloneSlots(const Inventory &src) throw(bad_alloc);
};

#endif
