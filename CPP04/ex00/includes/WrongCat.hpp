/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:17:00 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/29 23:17:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP

# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

using std::cout;
using std::endl;

class WrongCat: public WrongAnimal
{
	public:
	
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &src);

	WrongCat &operator=(const WrongCat &rhs);

	void	makeSound() const;
};

#endif
