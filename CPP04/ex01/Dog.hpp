/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:28:45 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/30 23:05:58 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP

# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

using std::cout;
using std::endl;

class Dog: public Animal
{
	public:
	
	Dog();
	Dog(const Dog &src);
	~Dog();

	Dog &operator=(const Dog &rhs);

	void	makeSound() const;

	private:

	Brain	*_brain;
};

#endif
