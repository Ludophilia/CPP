/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:05:34 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/18 21:15:55 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP

# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:

	FragTrap(void);
	FragTrap(const String &name);
	FragTrap(const FragTrap &src);
	~FragTrap(void);

	FragTrap &operator=(const FragTrap &rhs);

	void	attack(const String &target);

	void	highFivesGuys(void);
};

#endif
