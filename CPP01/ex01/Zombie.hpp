/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:58:48 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 21:43:50 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iostream>
# include <string>

using std::string;

class Zombie
{
	public:

	void	annouce(void) const;
	void	setName(string name);

	private:

	string	_name;
};

Zombie	*zombieHorde(int N, string name);


#endif
