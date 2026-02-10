/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/10 19:57:52 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

// What should be done?

// 4/02: Display the saved contacts as a list of 4 columns. Index, first name,
// last name, nickname.


int	main(void)
{
	PhoneBook	phonebook;
	String		uin;
	
	// User prompt (ADD, SEARCH, EXIT)
	while (1)
	{
		std::cout << "phonebook> ";
		std::cin >> uin;
		if (uin == "ADD")
		{
			if (phonebook.add_contact() == -1)
				return (1);
		}
		else if (uin == "SEARCH") // 4/02: Display the saved contacts...
		{
			// std::cout << "(2) search contact" << std::endl;
			// std::cout << std::setfill('x') << std::setw(30);
			// std::cout.width(10);
			// std::cout << std::setw(10);
			// std::cout << std::setiosflags(std::ios::right);
			// std::cout << 77 << "\n";
			// std::cout   << std::setw(10) << "Index |"
			// 			<< std::setw(10) << " first name |"
			// 			<< std::setw(10) << " last name |"
			// 			<< std::setw(10) << " nickname\n";
			if (phonebook.get_size() == 0)
			{
				std::cout << "No entries :(\n";
				// return 0
				break ; 
			}			
			
			std::cout << "size: " << phonebook.get_size() << "\n";

			std::cout   << "|"
						<< std::setw(10) << "index" << "|"
						<< std::setw(10) << "first name" << "|"
						<< std::setw(10) << "last name" << "|"
						<< std::setw(10) << "nickname" << "|"
						<< std::endl;

			for (int i = 0, t = phonebook.get_size(); i < t; i++)
			{
				Contact	*contact;

				contact = phonebook.get_contact(i);
				std::cout   << "|"
							<< std::setw(10) << i << "|"
							<< std::setw(10) << contact->get_field("first_name", 1) << "|"
							<< std::setw(10) << contact->get_field("last_name", 1) << "|"
							<< std::setw(10) << contact->get_field("nickname", 1) << "|"
							<< std::endl;
				
			}

			// Prompt the user again

			std::cout << "Which entry do you want details on?\n";
			
			int	uin2;

			std::cin >> uin2;

			std::cout << "You chose " << uin2 << " motherfucker\n";

			// Display the information, one field per line.



			// std::cout   << "|"
			// 			<< std::setw(10) << "0123456789" << "|"
			// 			<< std::setw(10) << "0123456789" << "|"
			// 			<< std::setw(10) << "0123456789" << "|"
			// 			<< std::setw(10) << "0123456789" << std::endl;

			// std::cout   << "|"
			// 			<< std::setw(10) << "01234" << "|"
			// 			<< std::setw(10) << "01234" << "|"
			// 			<< std::setw(10) << "01234" << "|"
			// 			<< std::setw(10) << "01234" << std::endl;

			// std::cout << 42 << "\n";
			// std::cout << "Index | first name | last name | nickname\n";

		}
		else if (uin == "EXIT" || std::cin.fail() || std::cin.eof())
		{
			std::cout << (uin == "EXIT" ? "" : "\n");			
			break ;
		}
		else
			std::cout << "usage: (ADD | SEARCH) a contact or EXIT phonebook\n";
		uin.clear();
	}
	return (0);
};
