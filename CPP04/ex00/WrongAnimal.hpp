/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:56:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/29 23:18:10 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

class WrongAnimal
{
	public:

	WrongAnimal();
	virtual ~WrongAnimal(); // Remove virtual no? As it should be Wrong...
	WrongAnimal(const WrongAnimal &src);

	WrongAnimal &operator=(const WrongAnimal &rhs);

	const string	&getType() const;
	void			makeSound() const;

	protected:

	string	type;
};

#endif
