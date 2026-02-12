/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:08:25 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/12 16:24:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"

# define CONTACT_MAX 8

class PhoneBook
{
	public:

	PhoneBook(void);

	Contact	*get_contact(int pos);
	int		add_contact(void);
	int		search_contact(void);

	private:

	Contact	contacts[CONTACT_MAX];
	int		nbr;

	int	proc_field(String uprompt, String &field) const;
	int	display_summary(void);
};

#endif