/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:37:49 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 21:45:19 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

# define HUMANA_HPP

# include "Weapon.hpp"
// NOTE = INCLUDES MUST BE INDEPENDENT FROM EACH OTHER

class HumanA
{
	public:

	HumanA(const string &name, Weapon &weapon);

	void	attack(void);

	private:
	
	Weapon	&_weapon;
	string	_name;
};

#endif
