/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:08:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/18 17:45:07 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(): _pos(0), _size(0) {}

// 18/07: Returning -1 is not proper C++... Consider exceptions, booleans, 
// empty objects instead
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

// 18/07: Returning -1 is not proper C++... Consider exceptions, booleans, 
// empty objects instead
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
	
	_pos = (_pos == 7) ? 0 : (_pos + 1);
	if (_size < CONTACT_MAX)
		_size++;
	return (0);
}

// 18/07: Returning -1 is not proper C++... Consider exceptions, booleans, 
// empty objects instead
int PhoneBook::search_contact()
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
	get_contact(entry)->display();
	return (0);
}

// 18/07: ...
Contact	*PhoneBook::get_contact(int pos)
{
	if (pos < 0 || pos > CONTACT_MAX - 1)
		return (NULL);
	return (_contacts + pos);
}

void	PhoneBook::display_summary()
{
	std::cout	<< "|"
				<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First name" << "|"
				<< std::setw(10) << "Last name" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < _size; i++)
		get_contact(i)->summarize(i);
}

// 18/07: Returning -1 is not proper C++... Consider exceptions, booleans, 
// empty objects instead
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
