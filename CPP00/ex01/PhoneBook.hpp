/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:08:25 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/27 21:35:46 by jegerman         ###   ########.fr       */
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
	
	void	add_contact();

	void	search_contact() const;

	void	display_summary() const;
	int		validate_input(const String &uin) const;
};

#endif
