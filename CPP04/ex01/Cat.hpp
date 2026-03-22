/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:17:00 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/20 21:20:40 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP

# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
	public:
	
	Cat(void);
	~Cat(void);
	Cat(const Cat &src);

	Cat &operator=(const Cat &rhs);

	void	makeSound(void) const;

	private:

	Brain	*brain;
};

#endif
