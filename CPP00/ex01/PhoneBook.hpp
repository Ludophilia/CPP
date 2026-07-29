/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:08:25 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/29 22:33:22 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <string>

# include "Contact.hpp"

# define CONTACT_MAX 8
# define FIELDS_NB 5

using std::string;

// typedef std::ios_base::failure ios_fail;
// using std::istream;

class PhoneBook
{
	public:

	PhoneBook();

	void	run();

	private:
	
	Contact	_contacts[CONTACT_MAX];
	int		_size;
	int		_pos;
	
	void	add_contact();

	void	search_contact() const;

	void	display_summary() const;
	int		validate_input(const string &uin) const;
};

#endif
