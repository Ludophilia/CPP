/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 22:48:24 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/12 15:23:20 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice &src): AMateria(src) {}

Ice::~Ice() {}

Ice	&Ice::operator=(const Ice &rhs)
{
	return ((void)rhs, *this);
}

void	Ice::use(ICharacter &target) const
{
	cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}

AMateria	*Ice::clone() const throw(bad_alloc)
{
	return (new Ice());
}
