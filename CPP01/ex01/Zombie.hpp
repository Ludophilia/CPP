/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:58:48 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/04 16:38:05 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iostream>
# include <string>

typedef std::string String;

class Zombie
{
	public:

	void	annouce(void) const;
	void	setName(String name);

	private:

	String	_name;
};

Zombie	*zombieHorde(int N, String name);


#endif
