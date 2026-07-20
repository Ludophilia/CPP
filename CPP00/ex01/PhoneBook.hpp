/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:08:25 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/20 22:42:21 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>

# define CONTACT_MAX 8

class PhoneBook
{
	public:

	PhoneBook();

	int		run();

	private:
	
	Contact	_contacts[CONTACT_MAX];
	int		_size;
	int		_pos;

	int		process_choice(const String &uin);
	
	int		add_contact();
	int		process_field(String uprompt, String &field) const;

	int		search_contact() const;
	void	display_summary() const;
	int		validate_input(String &uin) const;

};

#endif
