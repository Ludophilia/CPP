/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:58:41 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/13 20:24:20 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP

# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"
# include "Inventory.hpp"

using std::string;
using std::bad_alloc;

class AMateria;

class MateriaSource: public IMateriaSource
{
	public:

	MateriaSource();
	MateriaSource(const MateriaSource &src) throw(bad_alloc);
	~MateriaSource();

	MateriaSource	&operator=(const MateriaSource &rhs) throw(bad_alloc);

	void			learnMateria(AMateria *m);
	AMateria		*createMateria(const string &type) const throw(bad_alloc);

	protected:

	Inventory		_source;
};

#endif
