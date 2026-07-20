/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:08:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/20 22:48:40 by jegerman         ###   ########.fr       */
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
		{
			std::cout << "\nSomething wrong occurred :/\n";
			return (1);
		}
		if (uin == "EXIT" || std::cin.eof())
			return (0);
		if (process_choice(uin) == -1)
			return (2);
		uin.clear();
	}
}

int	PhoneBook::process_choice(const String &uin)
{
	if (uin == "ADD")
	{
		if (add_contact() == -1)
			return (-1);
	}
	else if (uin == "SEARCH")
	{
		if (search_contact() == -1)
			return (-1);
	}
	else
		std::cout << "usage: (ADD | SEARCH) a contact or EXIT phonebook\n";
	return (0);
}

// ################################################################


int	PhoneBook::add_contact()
{
	String		first, last, nickname, phone, secret;

	// 18/07: A better way of doing this?
	if (process_field("First name: ", first) == -1
		|| process_field("Last name: ", last) == -1
		|| process_field("Nickname: ", nickname) == -1
		|| process_field("Phone: ", phone) == -1
		|| process_field("Darkest secret: ", secret) == -1)
		return (-1);

	_contacts[_pos].set(first, last, nickname, phone, secret);
	
	_pos = (_pos == 7) ? 0 : _pos++;
	if (_size < CONTACT_MAX) _size++;
	return (0);
}

int	PhoneBook::process_field(String uprompt, String &field) const
{
	std::cout << uprompt;
	while (field.empty())
	{
		std::getline(std::cin, field);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << std::endl;
			return (-1);
		}
	}
	return (0);
}

// ################################################################

int PhoneBook::search_contact() const
{
	int		entry;
	String	uin;

	if (_size == 0)
		return (std::cout << "No entries :(\n", 0);
	display_summary();
	entry = -1;
	while (entry < 0 || entry > _size - 1)
	{
		std::cout << "Which entry do you want details on? ";
		std::getline(std::cin, uin);
		if (std::cin.eof() || std::cin.fail())
			return (std::cout << "\nSomething wrong occured :/\n", -1);
		entry = validate_input(uin);
		if (entry < 0 || entry > _size - 1)
			std::cout << "Invalid input :(\n";
	};
	_contacts[entry].display();
	return (0);
}

void	PhoneBook::display_summary() const
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

// 20/07: Is that complexity really necessary??
int	PhoneBook::validate_input(String &uin) const
{
	const char	*str;
	int			i, sg;

	str = uin.c_str();
	i = 0;
	sg = 0;
	if (str[i] == '+' || str[i] == '-')
		(i++, sg++);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == 0 && ((sg && i >= 2) || (!sg && i >= 1)))
		return (std::atoi(str));
	return (-1);
}
