/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:56:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/20 20:46:26 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include "Brain.hpp"

typedef std::string String;

class Animal
{
	public:
	
	Animal(void);
	virtual ~Animal(void);
	Animal(const Animal &src);

	Animal	&operator=(const Animal &rhs);

	const String	&getType(void) const;
	virtual void	makeSound(void) const;

	protected:
	
	String	type;
};

#endif
