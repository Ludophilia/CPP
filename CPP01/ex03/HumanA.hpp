/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:37:49 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/09 13:41:16 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	public:

	HumanA(const String &name, Weapon &weapon);
	~HumanA(void);

	void	attack(void);

	private:
	
	Weapon	&_weapon;
	String	_name;
};

#endif
