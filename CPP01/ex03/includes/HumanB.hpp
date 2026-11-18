/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:34:47 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/11 22:03:32 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

using std::string;
using std::cout;
using std::endl;

class HumanB
{
	public:

	HumanB(const string &name);

	void	attack() const;
	void	setWeapon(const Weapon &weapon);

	private:
	
	const Weapon	*_weapon;
	const string	_name;
};

#endif
