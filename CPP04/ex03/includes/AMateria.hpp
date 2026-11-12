/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 22:40:32 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/12 16:04:51 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP

# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

using std::string;
using std::cout;
using std::endl;
using std::bad_alloc;

class AMateria
{
	public:

	AMateria(); // = default in C++ 11
	AMateria(const string &type);
	AMateria(const AMateria &src);
	virtual ~AMateria();

	AMateria	&operator=(const AMateria &rhs);

	const string		&getType() const;
	virtual AMateria	*clone() const throw(bad_alloc) = 0;
	virtual void		use(ICharacter &target) const;

	protected:

	string	_type;
};

#endif
