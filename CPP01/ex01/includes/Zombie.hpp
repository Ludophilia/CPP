/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:58:48 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/10 20:02:04 by jegerman         ###   ########.fr       */
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
	
	void	annouce(void) const;
	void	setName(const string &name);

	private:

	string	_name;
};

Zombie	*zombieHorde(int N, string name);

#endif
