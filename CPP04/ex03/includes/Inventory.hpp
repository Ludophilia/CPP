/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 22:28:47 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/12 20:10:30 by jegerman         ###   ########.fr       */
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


	private:

	static const int	MAX_SLOTS = 4;
	
	AMateria			*_slot[MAX_SLOTS];
	int					_size;

	void				_init();
	void 				_clone(const Inventory &src) throw(bad_alloc);
	void				_cleanup(bool fwd, int i);

};

#endif
