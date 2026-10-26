/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:05:34 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/26 23:42:02 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP

# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

using std::string;
using std::cout;
using std::endl;

// When virtual inheritance is involved, the most-derived class, DiamondTrap,
// will be responsible for initializing the virtual base class ClapTrap.
// class FragTrap: public ClapTrap
class FragTrap: virtual public ClapTrap
{
	public:

	FragTrap();
	FragTrap(const string &name);
	FragTrap(const FragTrap &src);
	~FragTrap();

	FragTrap &operator=(const FragTrap &rhs);

	void	highFivesGuys();
};

#endif
