/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:37:49 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/11 21:45:13 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

using std::string;
using std::cout;
using std::endl;

class HumanA
{
	public:

	HumanA(const string &name, const Weapon &weapon);

	void	attack() const;

	private:

	const Weapon	&_weapon;
	const string	_name;
};

#endif
