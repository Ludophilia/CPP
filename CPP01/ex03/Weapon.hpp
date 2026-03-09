/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:07:09 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/09 14:16:26 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP

# include <string> 
# include <iostream> 

typedef std::string String;

class Weapon
{
	public:
		Weapon(const String &type);

		const String	&getType(void) const;
		void			setType(String newType);
	
	private:
		String	_type;
};

#endif
