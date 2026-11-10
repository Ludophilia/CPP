/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:42:27 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/10 19:51:48 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP

# define IMATERIASOURCE_HPP

#include <string>

using std::string;

// class AMateria;
#include "AMateria.hpp"

class IMateriaSource
{
	public:

	virtual AMateria	*createMateria(const string &type) = 0;
	virtual void		learnMateria(AMateria *) = 0;

	virtual ~IMateriaSource() {};
};

#endif
