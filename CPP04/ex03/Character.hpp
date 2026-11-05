/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 23:20:25 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/05 23:37:58 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP

# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

using std::string;

class Character: public ICharacter
{
	public:

	Character();
	Character(const string &name);
	Character(const Character &src); // /!\ DEEP COPIES
	~Character();

	Character	&operator=(const Character &rhs); // /!\ DEEP COPIES

	const string	&getName() const;

	void			equip(AMateria* m);
	void 			unequip(int idx);
	void 			use(int idx, ICharacter &target);

	protected:

	static const int	MAX_MATERIA = 4;

	string				_name;
	AMateria			*slot[MAX_MATERIA]; // /!\ DEEP COPIES
};

#endif
