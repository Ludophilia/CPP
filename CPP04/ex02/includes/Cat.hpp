/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:17:00 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/02 21:21:49 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP

# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

using std::cout;
using std::endl;

class Cat: public AAnimal
{
	public:
	
	Cat();
	Cat(const Cat &src);
	~Cat();

	Cat &operator=(const Cat &rhs);

	void	makeSound() const;

	private:

	Brain	*_brain;
};

#endif
