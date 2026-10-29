/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:28:45 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/29 23:14:11 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP

# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

using std::cout;
using std::endl;

class Dog: public Animal
{
	public:
	
	Dog();
	~Dog();
	Dog(const Dog &src);

	Dog &operator=(const Dog &rhs);

	void	makeSound() const;
};

#endif
