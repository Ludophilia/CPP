/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:05:34 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/23 23:16:01 by jegerman         ###   ########.fr       */
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

class FragTrap: public ClapTrap // virtual
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
