/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:21:48 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/26 23:24:50 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP

# define DIAMONDTRAP_HPP

# include <string>
# include <iostream>

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

using std::string;
using std::cout;
using std::endl;

// When virtual inheritance is involved, the most-derived class 
// is responsible for initializing the virtual base class.
class DiamondTrap: public FragTrap, public ScavTrap // Order matter for the 
// construction.
{
	public:

	DiamondTrap();
	// DiamondTrap(const string &name);
	// DiamondTrap(const DiamondTrap &src);
	~DiamondTrap();
	// DiamondTrap &operator=(const DiamondTrap &rhs);

	

	private:

	string	_name;
};

#endif
