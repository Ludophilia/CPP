/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 22:40:32 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/03 23:27:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP

# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

using std::string;

class AMateria
{
	public:

	// AMateria();
	AMateria(const string &type);
	// AMateria(const AMateria &src);
	// ~AMateria();

	// AMateria	&operator=(const AMateria &rhs);
	
	const string		&getType() const; // Returns the materia type
	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter& target) const; // const added

	protected:

	// string	_type;
};

#endif
