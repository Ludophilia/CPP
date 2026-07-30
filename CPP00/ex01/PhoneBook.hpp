/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:08:25 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/30 22:45:22 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <string>

# include "Contact.hpp"

// # define CONTACT_NB 8
// # define FIELDS_NB 5

using std::string;

class PhoneBook
{
	public:

	PhoneBook();

	void	run();

	private:

	static const int	_contact_nb = 8;
	static const int	_field_nb = 5;
	Contact				_contacts[_contact_nb];
	int					_size;
	int					_pos;
	
	void	add_contact();

	void	search_contact() const;

	void	display_summary() const;
	int		validate_input(const string &uin) const;
};

#endif
