/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:58:48 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 21:34:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

class Zombie
{
	public:

	Zombie(const string &name);
	~Zombie();

	void	annouce(void) const;

	private:

	string	_name;
};

void	randomChump(string);
Zombie	*newZombie(string);

#endif
