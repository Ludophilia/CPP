/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:17:00 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/19 23:44:13 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP

# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

typedef std::string String;

class WrongCat: public WrongAnimal
{
	public:
	
	WrongCat(void);
	~WrongCat(void);
	WrongCat(const WrongCat &src);

	WrongCat &operator=(const WrongCat &rhs);

	void	makeSound(void) const;
};

#endif
