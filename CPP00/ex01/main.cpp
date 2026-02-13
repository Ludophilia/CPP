/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/13 19:14:11 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

static int	process_choice(String &uin, PhoneBook &phonebook)
{
	if (uin == "ADD")
	{
		if (phonebook.add_contact() == -1)
			return (-1);
	}
	else if (uin == "SEARCH")
	{
		if (phonebook.search_contact() == -1)
			return (-1);
	}
	else
		std::cout << "usage: (ADD | SEARCH) a contact or EXIT phonebook\n";
	return (0);
}

int	main(void)
{
	PhoneBook	phonebook;
	String		uin;

	while (1)
	{
		std::cout << "phonebook> ";
		std::getline(std::cin, uin);
		if (std::cin.fail())
		{
			std::cout << "\nSomething wrong occured :/\n";
			return (1);
		}
		if (uin == "EXIT" || std::cin.eof())
			return (0);
		if (process_choice(uin, phonebook) == -1)
			return (2);
		uin.clear();
	}
	return (0);
}
