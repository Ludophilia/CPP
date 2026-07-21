/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:08:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/21 22:54:41 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

// 17/07, 18/07, 20/07: Please learn how to manage errors in C++. Returning
// -1 is not proper C++... Consider exceptions, booleans, empty objects instead

// 20/07: Check return types. That's not C, again...

PhoneBook::PhoneBook(): _size(0), _pos(0) {}

int	PhoneBook::run()
{
	String	uin;

	while (1)
	{
		std::cout << "phonebook> ";
		std::getline(std::cin, uin);
		if (std::cin.fail())
			return (1);
		if (uin == "EXIT" || std::cin.eof())
			return (0);
		if (uin == "ADD")
		{
			if (add_contact() == -1)
				return (2);
		}
		else if (uin == "SEARCH")
		{
			if (search_contact() == -1)
				return (2);
		}
		else
			std::cout << "usage: (ADD | SEARCH) a contact or EXIT phonebook\n";
		uin.clear();
	}
}

// Removed int		PhoneBook::process_choice(const String &uin)

// ################################################################

// 	Removed int		process_field(String uprompt, String &field) const;

int	PhoneBook::add_contact()
{
	String					fields[5];
	const char *const		prompts[5] = {"First name: ", "Last name: ",
							"Nickname: ", "Phone: ", "Darkest secret: "};

	for (int i = 0; i < 5; i++)
	{
		std::cout << prompts[i];
		while (fields[i].empty())
		{
			std::getline(std::cin, fields[i]);
			if (std::cin.eof() || std::cin.fail())
			{
				std::cout << std::endl;
				return (-1);
			}
		}
	}
	_contacts[_pos].set(fields);
	_pos = (_pos == 7) ? 0 : _pos++;
	if (_size < CONTACT_MAX) _size++;
	return (0);
}

// ################################################################

void	PhoneBook::summarize() const
{
	std::cout	<< '|'
				<< std::setw(10) << "Index" << '|'
				<< std::setw(10) << "First name" << '|'
				<< std::setw(10) << "Last name" << '|'
				<< std::setw(10) << "Nickname" << '|'
				<< std::endl;
	for (int i = 0; i < _size; i++)
		_contacts[i].summarize(i);
}

int PhoneBook::search_contact() const
{
	int		entry;
	String	uin;

	if (_size == 0)
	{
		std::cout << "No entries :(" << std::endl;
		return (0);
	}
	summarize();
	entry = -1;
	while (entry < 0 || entry > _size - 1)
	{
		std::cout << "Which entry do you want details on? ";
		std::getline(std::cin, uin);
		if (std::cin.eof() || std::cin.fail())
			return (-1);
		entry = validate_input(uin);
		if (entry < 0 || entry > _size - 1)
			std::cout << "Invalid input :(\n";
	};
	_contacts[entry].display();
	return (0);
}

int	PhoneBook::validate_input(const String &uin) const
{
	int		i, sign, res;

	i = 0;
	sign = 0;
	if (uin[i] == '+' || uin[i] == '-')
	{
		i++;
		sign++;
	}
	while (uin[i] >= '0' && uin[i] <= '9')
		i++;
	if (i == uin.size() 
		&& ((sign && i >= 2) || (!sign && i >= 1)))
	{
		res = std::atoi(uin.c_str());
		return (res);
	}
	return (-1);
}
