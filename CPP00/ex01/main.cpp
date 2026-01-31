/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/01/31 18:37:05 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

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
		else if (uin == "SEARCH")
		{
			// 31/01 : How are you going to win the game against Paris tomorrow?
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
