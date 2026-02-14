/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:08:25 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/14 16:48:14 by jegerman         ###   ########.fr       */
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

	PhoneBook(void);

	int		get_size(void) const; 
	Contact	*get_contact(int pos);
	int		add_contact(void);
	int		search_contact(void);

	private:

	Contact	_contacts[CONTACT_MAX];
	int		_size;
	int		_pos;

	int	validate_input(String &uin) const;
	int	process_field(String uprompt, String &field) const;
	int	display_summary(void);
};

#endif
