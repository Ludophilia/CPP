/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:08:25 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/10 18:50:37 by jegerman         ###   ########.fr       */
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

	int		get_size(void) const;
	Contact	*get_contact(int pos);
	int		add_contact(void);

	private:

	Contact	contacts[CONTACT_MAX];
	int		nbr;

	int	proc_field(std::string uprompt, std::string *field) const;
};

#endif