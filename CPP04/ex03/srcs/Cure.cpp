/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 23:13:05 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/05 23:14:33 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure &src): AMateria(src) {}

Cure::~Cure() {}

Cure	&Cure::operator=(const Cure &rhs)
{
	return ((void)rhs, *this);
}

void	Cure::use(ICharacter &target) const
{
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}

AMateria	*Cure::clone() const
{
	return (new Cure());
}
