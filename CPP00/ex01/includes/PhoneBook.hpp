/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:08:25 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/27 00:11:30 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <string>

# include "Contact.hpp"

using std::atoi;

using std::string;

using std::istream;

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

using std::getline;
using std::setw;

class PhoneBook
{
	public:

	PhoneBook();

	void	run();

	private:

	static const int	_contactNb = 8;
	static const int	_fieldNb = 5;
	Contact				_contacts[_contactNb];
	int					_size;
	int					_pos;
	
	void				add();
	void				search() const;
	void				summarize() const;
	int					validate(const string &uin) const;
};

#endif
