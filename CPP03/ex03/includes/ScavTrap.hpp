/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:05:34 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/27 22:58:18 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP

# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

using std::string;
using std::cout;
using std::endl;

// When virtual inheritance is involved, the most-derived class, DiamondTrap,
// will be responsible for initializing the virtual base class ClapTrap.
// class ScavTrap: public ClapTrap
class ScavTrap: virtual public ClapTrap
{
	public:

	ScavTrap();
	ScavTrap(const string &name);
	ScavTrap(const ScavTrap &src);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &rhs);

	void	attack(const string &target);
	void	guardGate();

	protected:

	static const int	_HP_DFLT = 100;
	static const int	_EP_DFLT = 50;
	static const int	_AD_DFLT = 20;
};

#endif
