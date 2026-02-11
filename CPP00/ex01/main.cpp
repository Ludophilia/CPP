/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/11 21:42:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

int	main(void)
{
	PhoneBook	phonebook;
	String		uin;
	
	while (1)
	{
		std::cout << "phonebook> ";
		std::cin >> uin;
		if (uin == "ADD")
		{
			// Darkest secret: 5000 prototypes and no breakthroughs
			// phonebook> uin was: prototypes
			// usage: (ADD | SEARCH) a contact or EXIT phonebook
			// phonebook> uin was: and
			// usage: (ADD | SEARCH) a contact or EXIT phonebook
			// phonebook> uin was: no
			// usage: (ADD | SEARCH) a contact or EXIT phonebook
			// phonebook> uin was: breakthroughs
			// usage: (ADD | SEARCH) a contact or EXIT phonebook
			if (phonebook.add_contact() == -1)
				return (1);
		}
		else if (uin == "SEARCH")
		{
			if (phonebook.search_contact() == -1)
				return (2);
		}
		else if (uin == "EXIT" || std::cin.fail() || std::cin.eof())
			return (std::cout << (uin == "EXIT" ? "" : "\n"), 0);			
		else
		{
			std::cout << "uin was: " << uin << std::endl; 
			std::cout << "usage: (ADD | SEARCH) a contact or EXIT phonebook\n";
		}
		uin.clear();
	}
	return (0);
};
