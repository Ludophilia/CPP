/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:29:19 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/21 22:25:12 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H

# define CLAPTRAP_H

# include <string>
# include <iostream>

using std::string;
using std::cout;
using std::endl;

class ClapTrap
{
	public:

	ClapTrap();
	ClapTrap(const string &name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &rhs);

	void	attack(const string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	protected:

	string		_name;
	int			_hitPts;
	int			_energyPts;
	int			_attackDmg;
};

#endif
