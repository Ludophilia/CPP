/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 22:40:32 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/05 23:15:52 by jegerman         ###   ########.fr       */
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

class AMateria
{
	public:

	AMateria(); // = default in C++ 11
	AMateria(const string &type);
	AMateria(const AMateria &src);
	virtual ~AMateria();

	AMateria	&operator=(const AMateria &rhs);

	const string		&getType() const;
	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target) const; // const added

	protected:

	string	_type;
};

#endif
