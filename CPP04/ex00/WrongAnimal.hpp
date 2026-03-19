/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:56:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/19 23:13:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

typedef std::string String;

class WrongAnimal
{
	public:
	
	WrongAnimal(void);
	virtual ~WrongAnimal(void);
	WrongAnimal(const WrongAnimal &src);

	WrongAnimal &operator=(const WrongAnimal &rhs);

	const String	&getType(void) const;
	void			makeSound(void) const;

	protected:
	
	String	type;
};

#endif
