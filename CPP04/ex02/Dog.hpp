/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:28:45 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/24 01:26:18 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP

# define DOG_HPP

# include "AAnimal.hpp"

class Dog: public AAnimal
{
	public:
	
	Dog(void);
	~Dog(void);
	Dog(const Dog &src);

	Dog &operator=(const Dog &rhs);

	void	makeSound(void) const;

	private:

	Brain	*_brain;
};

#endif
