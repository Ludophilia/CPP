/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:04:09 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/05 21:52:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _type("unknown") {}

AMateria::AMateria(const string &type): _type(type) {}

AMateria::AMateria(const AMateria &src): _type(src._type) {}

AMateria::~AMateria() {}

AMateria		&AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

const string	&AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter &target) const
{
	cout << "* uses materia powers on " << target.getName() << " *" << endl;
}
