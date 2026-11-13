/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:58:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/13 22:38:20 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
	: _source() {}

MateriaSource::MateriaSource(const MateriaSource &src) throw(bad_alloc)
	: _source(src._source) {}

MateriaSource::~MateriaSource() {}

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs)
	throw(bad_alloc)
{
	if (this != &rhs)
		_source = rhs._source;
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *m)
{
	_source.add(m);
}

AMateria	*MateriaSource::createMateria(const string &type) const
	throw(bad_alloc)
{
	AMateria *sourceMateria = _source.get(type);
	
	if (sourceMateria != NULL)
		return (sourceMateria->clone());
	return (0);
}
