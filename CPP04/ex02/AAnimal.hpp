/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:56:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/24 01:17:09 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP

# define AAnimal_HPP

# include "Brain.hpp"

typedef std::string String;

class AAnimal
{
	public:
	
	AAnimal(void);
	virtual ~AAnimal(void);
	AAnimal(const AAnimal &src);

	AAnimal	&operator=(const AAnimal &rhs);

	const String	&getType(void) const;
	virtual void	makeSound(void) const = 0;

	protected:
	
	String	type;
};

#endif
