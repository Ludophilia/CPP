/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:34:47 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 21:45:33 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

# define HUMANB_HPP

# include "Weapon.hpp"
// NOTE = INCLUDES MUST BE INDEPENDENT FROM EACH OTHER

class HumanB
{
	public:

	HumanB(const string &name);

	void	attack(void);

	void	setWeapon(Weapon &weapon);

	private:
	
	Weapon	*_weapon;
	string	_name;
};

#endif
