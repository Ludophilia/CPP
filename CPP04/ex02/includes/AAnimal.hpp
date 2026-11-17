/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:56:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/02 21:14:01 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

class AAnimal
{
	public:

	AAnimal();
	AAnimal(const AAnimal &src);
	virtual ~AAnimal();

	AAnimal &operator=(const AAnimal &rhs);

	const string	&getType() const;
	virtual void	makeSound() const = 0;

	protected:

	string	type;
};

#endif
