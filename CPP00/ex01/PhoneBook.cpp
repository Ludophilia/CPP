/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:08:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/03 15:54:21 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _size(0), _pos(0) {}

void	PhoneBook::run()
{
	string	uin;

	while (1)
	{
		std::cout << "phonebook> ";
		std::getline(std::cin, uin);
		if (uin == "EXIT" || std::cin.eof())
		{
			if (!std::cin) std::cout << std::endl;
			return ;
		}
		if (std::cin.fail())
			throw (std::istream::failure("cin failure"));
		if (uin == "ADD")
			add_contact();
		else if (uin == "SEARCH")
			search_contact();
		else
			std::cout << "usage: (ADD | SEARCH) a contact"
				" or EXIT phonebook\n";
		if (!std::cin)
			break ;
		else
			uin.clear();
	}
}

void	PhoneBook::add_contact()
{
	string			fields[_field_nb];
	const string	prompts[_field_nb] = {"First name: ", "Last name: ",
					"Nickname: ", "Phone: ", "Darkest secret: "};

	for (int i = 0; i < _field_nb; i++)
	{
		std::cout << prompts[i];
		while (fields[i].empty())
		{
			std::getline(std::cin, fields[i]);
			if (std::cin.eof())
			{
				std::cout << std::endl;
				return ;
			}
			if (std::cin.fail())
				throw (std::istream::failure("cin failure"));
		}
	}
	_contacts[_pos].set(fields);
	_pos = (_pos == _contact_nb - 1) ? 0 : (_pos + 1);
	if (_size < _contact_nb) _size += 1;
}

void	PhoneBook::search_contact() const
{
	int			entry = -1;
	string		uin;

	if (_size == 0)
	{
		std::cout << "No entries :(" << std::endl;
		return ;
	}
	display_summary();
	while (entry < 0 || entry > _size - 1)
	{
		std::cout << "Which entry do you want details on? ";
		std::getline(std::cin, uin);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
		if (std::cin.fail())
			throw (std::istream::failure("cin failure")); 
		entry = validate_input(uin);
		if (entry < 0 || entry > _size - 1)
		{
			std::cout << "Invalid input :(\n";
			return ;
		}
	};
	_contacts[entry].display();
}

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

int	PhoneBook::validate_input(const string &uin) const
{
	int		sign = 0, entry = -1;
	size_t	i = 0;

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
