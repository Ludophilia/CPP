/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:08:25 by jegerman          #+#    #+#             */
/*   Updated: 2026/01/29 17:59:57 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:

	PhoneBook(void);
	~PhoneBook(void);

	int	add_contact(void); // 29/01 - No args?
	int	print_contacts(void); // 29/01 - No args?

	// Then, prompt the user again for the index of the entry to display...

	private:
	
	Contact	contacts[8];
	int		nbr;
};

#endif