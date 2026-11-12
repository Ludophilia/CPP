/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:58:41 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/12 15:31:47 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP

# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"

using std::string;
using std::bad_alloc;

class AMateria;

class MateriaSource: public IMateriaSource
{
	public:

	// MateriaSource();
	// MateriaSource(const MateriaSource &src);
	// ~MateriaSource();

	// MateriaSource	&operator=(const MateriaSource &rhs);

	void			learnMateria(AMateria *m);
	AMateria		*createMateria(const string &type) throw(bad_alloc);

	protected:

	// Will be replaced by Inventory?
	
	static const int	MAX_SLOTS = 4;

	AMateria			*_slot[MAX_SLOTS];
	int					_slotSize;
};

#endif
