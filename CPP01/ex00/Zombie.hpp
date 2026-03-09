/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:58:48 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/03 19:05:20 by jegerman         ###   ########.fr       */
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

	Zombie(String name);
	~Zombie(void);

	void	annouce(void) const;

	private:

	String	_name;
};

void	randomChump(String name);
Zombie	*newZombie(String name);

#endif
