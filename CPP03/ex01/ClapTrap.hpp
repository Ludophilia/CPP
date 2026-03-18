/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:29:19 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/18 00:49:22 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H

# define CLAPTRAP_H

# include <string>
# include <iostream>

typedef std::string String;

class ClapTrap
{
	public:

	ClapTrap(void);
	ClapTrap(const String &name);
	ClapTrap(const ClapTrap &src);
	virtual ~ClapTrap(void);

	ClapTrap &operator=(const ClapTrap &rhs);

	void	attack(const String &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	protected:

	std::string _name;
	int			_hit_pts;
	int			_energy_pts;
	int			_attack_dmg;
};

#endif

