/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:56:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/04 21:59:53 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

class Animal
{
	public:

	Animal();
	Animal(const Animal &src);
	virtual ~Animal();

	Animal &operator=(const Animal &rhs);

	const string	&getType() const;
	virtual void	makeSound() const;

	protected:

	string	type;
};

#endif
