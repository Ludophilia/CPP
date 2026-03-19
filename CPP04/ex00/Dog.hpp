/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:28:45 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/19 22:38:46 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP

# define DOG_HPP

# include "Animal.hpp"

typedef std::string String;

class Dog: public Animal
{
	public:
	
	Dog(void);
	~Dog(void);
	Dog(const Dog &src);

	Dog &operator=(const Dog &rhs);

	void	makeSound(void) const;
};

#endif
