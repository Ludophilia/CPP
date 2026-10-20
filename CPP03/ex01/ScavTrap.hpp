/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:05:34 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/20 21:23:38 by jegerman         ###   ########.fr       */
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

class ScavTrap: public ClapTrap
{
	public:

	ScavTrap();
	ScavTrap(const string &name);
	ScavTrap(const ScavTrap &src);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &rhs);

	void	attack(const string &target);

	void	guardGate();
};

#endif