/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 23:20:25 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/13 20:25:50 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP

# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Inventory.hpp"

using std::string;
using std::bad_alloc;

class Character: public ICharacter
{
	public:

	Character();
	Character(const string &name);
	Character(const Character &src) throw(bad_alloc);
	~Character();

	Character		&operator=(const Character &rhs) throw(bad_alloc);

	const string	&getName() const;

	void			equip(AMateria *m);
	void 			use(int idx, ICharacter &target) const;
	void 			unequip(int idx);

	protected:

	string				_name;
	Inventory			_inventory;
};

#endif
