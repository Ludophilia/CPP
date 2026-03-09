/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:34:47 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/09 14:53:27 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	public:

	HumanB(const String &name);

	void	attack(void);

	void	setWeapon(Weapon &weapon);

	private:
	
	Weapon	*_weapon;
	String	_name;
};

#endif
