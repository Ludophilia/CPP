/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:17:00 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/29 23:14:17 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP

# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

using std::cout;
using std::endl;

class Cat: public Animal
{
	public:
	
	Cat();
	~Cat();
	Cat(const Cat &src);

	Cat &operator=(const Cat &rhs);

	void	makeSound() const;
};

#endif
