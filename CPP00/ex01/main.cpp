/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/04 15:15:26 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

// 4/02: Display the saved contacts as a list of 4 columns. Index, first name,
// last name, nickname.

// What should be done?

// ==========


int	main(void)
{
	PhoneBook	phonebook;
	String		uin;
	
	// User prompt (ADD, SEARCH, EXIT)
	while (1)
	{
		std::cout << "phonebook> ";
		std::cin >> uin;
		if (uin == "ADD" && phonebook.add_contact() == -1)
			return (1);
		// 4/02: Display the saved contacts...
		else if (uin == "SEARCH")
		{
			std::cout << "(2) search contact" << std::endl;
		}
		else if (uin == "EXIT" || std::cin.fail() || std::cin.eof())
		{
			std::cout << (uin == "EXIT" ? "" : "\n");			
			break ;
		}
		uin.clear();
	}
	return (0);
};
