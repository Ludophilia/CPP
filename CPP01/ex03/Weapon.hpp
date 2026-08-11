/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:07:09 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/11 21:52:26 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP

# include <string>

using std::string;

class Weapon
{
	public:
		Weapon(const string &type);

		const string	&getType() const;
		void			setType(const string &newType);
	
	private:
		string	_type;
};

#endif
