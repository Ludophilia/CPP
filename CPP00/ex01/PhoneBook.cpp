/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:08:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/27 21:55:03 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

// 17/07, 18/07, 20/07: Please learn how to manage errors in C++. Returning
// -1 is not proper C++... Consider exceptions, booleans, empty objects instead

// 20/07: Check return types. That's not C, again...


// ################################################################
// ################################################################

// 27/07: run(), search_contact(), add_contact()
//		   Those are the member functions to adapt to the C++ way of handling errors

			
PhoneBook::PhoneBook(): _size(0), _pos(0) {}

int	PhoneBook::run()
{
	String	uin;

	std::cin.exceptions(std::cin.failbit | std::cin.badbit);
	while (1)
	{
		std::cout << "phonebook> ";
		std::getline(std::cin, uin);
		// if (std::cin.fail())
		// 	throw (1); // Exception
		if (uin == "EXIT" || std::cin.eof())
			return (0);
		if (uin == "ADD")
		{
			add_contact(); // == -1)
			// throw (2); // Exception
		}
		else if (uin == "SEARCH")
		{
			search_contact(); // == -1)
			// throw (2); // Exception
		}
		else
			std::cout << "usage: (ADD | SEARCH) a contact or EXIT phonebook\n";
		uin.clear();
	}
	return (0);
}

void	PhoneBook::add_contact()
{
	String					fields[5];
	const String			prompts[5] = {"First name: ", "Last name: ",
							"Nickname: ", "Phone: ", "Darkest secret: "};

	for (int i = 0; i < 5; i++)
	{
		std::cout << prompts[i];
		while (fields[i].empty())
		{
			std::getline(std::cin, fields[i]);
			if (std::cin.eof()) // || std::cin.fail())
			{
				std::cout << std::endl;
				return ;
				// return (-1); // Exception
			}
		}
	}
	_contacts[_pos].set(fields);
	_pos = (_pos == 7) ? 0 : _pos++;
	if (_size < CONTACT_MAX) _size++;
	// return (0);
}


void	PhoneBook::search_contact() const
{
	int					entry;
	String				uin;

	if (_size == 0)
	{
		std::cout << "No entries :(" << std::endl;
		return ; //(0);
	}
	display_summary();
	entry = -1;
	while (entry < 0 || entry > _size - 1)
	{
		std::cout << "Which entry do you want details on? ";
		std::getline(std::cin, uin);
		if (std::cin.eof()) //|| std::cin.fail())
		{
			std::cout << std::endl;
			return ; //(-1); // Exception
		}
		entry = validate_input(uin);
		if (entry < 0 || entry > _size - 1)
			std::cout << "Invalid input :(\n";
	};
	_contacts[entry].display();
	// return (0);
}

// ################################################################
// ################################################################


void	PhoneBook::display_summary() const
{
	std::cout	<< '|' << std::setw(10) << "Index"
				<< '|' << std::setw(10) << "First name"
				<< '|' << std::setw(10) << "Last name"
				<< '|' << std::setw(10) << "Nickname"
				<< '|' << std::endl;
	for (int i = 0; i < _size; i++)
		_contacts[i].summarize(i);
}

int	PhoneBook::validate_input(const String &uin) const
{
	int		i, sign, entry;

	i = 0;
	sign = 0;
	if (uin[i] == '+' || uin[i] == '-')
	{
		sign++;
		i++;
	}
	while (uin[i] >= '0' && uin[i] <= '9')
		i++;
	if (i == uin.size() 
		&& ((sign && i >= 2) || (!sign && i >= 1)))
	{
		entry = std::atoi(uin.c_str());
		return (entry);
	}
	return (-1);
}
