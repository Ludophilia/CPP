/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/01/30 17:57:47 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

int	main(void)
{
	PhoneBook		phonebook;
	std::string		uin;
	
	// User prompt (ADD, SEARCH, EXIT)
	while (1)
	{
		std::cout << "phonebook> ";
		std::cin >> uin;

		// 30/01

		// Prompted to input the information of the new contact one field at a time. 
		// Add the contact to the phonebook, once all the fields have been completed.
		// The contact fields are: first name, last name, nickname, phone number, and
		// darkest secret. A saved contact can’t have empty fields.

		if (uin == "ADD")
			break ;
		else if (uin == "SEARCH")
			break ;
		else if (uin == "EXIT" || std::cin.fail() || std::cin.eof())
			break ;
		uin.clear();
	}
	return (0);
};
