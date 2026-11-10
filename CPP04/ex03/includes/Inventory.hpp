/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 22:28:47 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/10 23:40:52 by jegerman         ###   ########.fr       */
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
	Inventory(const Inventory &src);
	~Inventory();

	Inventory &operator=(const Inventory &rhs);

	void	cleanUp();

	// void			_initSlots();
	// void			_copySourceSlots(const Character &src);
	// void			_cleanUpSlots();


	// AMateria			*getSlots();
	// int					getSize();
	// int					setSize();

	private:

	static const int	MAX_SLOTS = 4;
	
	// const int  			_maxSlots = 4;
	AMateria			*_slot[MAX_SLOTS];
	int					_size;
};

#endif
