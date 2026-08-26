/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:08:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/27 00:08:25 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _size(0), _pos(0) {}

void	PhoneBook::run()
{
	string	uin;

	while (1)
	{
		cout << "phonebook> ";
		getline(cin, uin);
		if (uin == "EXIT" || cin.eof())
		{
			if (!cin)
				cout << endl;
			return ;
		}
		if (cin.fail())
			throw (istream::failure("cin failure"));
		if (uin == "ADD")
			add();
		else if (uin == "SEARCH")
			search();
		else
			cout << "usage: (ADD | SEARCH) a contact"
				" or EXIT phonebook\n";
		if (!cin)
			break ;
		else
			uin.clear();
	}
}

void	PhoneBook::add()
{
	string			fields[_fieldNb];
	const string	prompts[_fieldNb] = {"First name: ", "Last name: ",
					"Nickname: ", "Phone: ", "Darkest secret: "};

	for (int i = 0; i < _fieldNb; i++)
	{
		cout << prompts[i];
		while (fields[i].empty())
		{
			getline(cin, fields[i]);
			if (cin.eof())
			{
				cout << endl;
				return ;
			}
			if (cin.fail())
				throw (istream::failure("cin failure"));
		}
	}
	_contacts[_pos].set(fields);
	_pos = (_pos == _contactNb - 1) ? 0 : (_pos + 1);
	if (_size < _contactNb) _size += 1;
}

void	PhoneBook::search() const
{
	int			entry = -1;
	string		uin;

	if (_size == 0)
	{
		cout << "No entries :(" << endl;
		return ;
	}
	summarize();
	while (entry < 0 || entry > _size - 1)
	{
		cout << "Which entry do you want details on? ";
		getline(cin, uin);
		if (cin.eof())
		{
			cout << endl;
			return ;
		}
		if (cin.fail())
			throw (istream::failure("cin failure")); 
		entry = validate(uin);
		if (entry < 0 || entry > _size - 1)
		{
			cout << "Invalid input :(\n";
			return ;
		}
	}
	_contacts[entry].display();
}

void	PhoneBook::summarize() const
{
	cout	<< '|' << setw(10) << "Index"
				<< '|' << setw(10) << "First name"
				<< '|' << setw(10) << "Last name"
				<< '|' << setw(10) << "Nickname"
				<< '|' << endl;
	for (int i = 0; i < _size; i++)
		_contacts[i].summarize(i);
}

int	PhoneBook::validate(const string &uin) const
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
		entry = atoi(uin.c_str());
		return (entry);
	}
	return (-1);
}
