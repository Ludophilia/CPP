/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:08:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/23 22:05:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

// 17/07, 18/07, 20/07: Please learn how to manage errors in C++. Returning
// -1 is not proper C++... Consider exceptions, booleans, empty objects instead

// 20/07: Check return types. That's not C, again...

/* 22/07, 23/07

#include <iostream>
#include <exception>
#include <string>

// An exception propagates up to the main caller
void d()
{
    throw std::runtime_error("Bro wtf?");  
    // throw std::exception(); 
    // throw std::bad_alloc();
    // throw "I AM ERROR.";
    // throw 42;
    // throw std::string("NAN MAIS SERIEUX QUOI");
    std::cout << "This will never be printed(3)\n";
}

void c()
{
    d();
    std::cout << "This will never be printed (2)\n";
}

void b()
{
    c();
}

void a()
{
    b();
    std::cout << "This will never be printed (1)\n";
}

int main()
{
    try
    {
        a();
    }
    catch (const char* msg) {
        std::cout << "Error (char *): " << msg;
    }
    catch (const int nb) {
        std::cout << "Error (nb): " << nb; 
    }
    catch (const std::string &str) {
        std::cout << "Error (string): " << str;
    }
    catch (const std::exception &e) {
        std::cout << "Error (exception): " << e.what(); 
    }
    std::cout << std::endl;
}



*/

PhoneBook::PhoneBook(): _size(0), _pos(0) {}

int	PhoneBook::run()
{
	String	uin;

	while (1)
	{
		std::cout << "phonebook> ";
		std::getline(std::cin, uin);
		if (std::cin.fail())
			throw (1); // 22/07: Just the beginning...
		if (uin == "EXIT" || std::cin.eof())
			return (0);
		if (uin == "ADD")
		{
			// 22/07: Let the thrown exit code propagate to main? 
			// Use a try catch block there and throw again?
			// I don't have any idea.
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

// ################################################################

int	PhoneBook::add_contact()
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

int PhoneBook::search_contact() const
{
	int					entry;
	String				uin;

	if (_size == 0)
	{
		std::cout << "No entries :(" << std::endl;
		return (0);
	}
	display_summary();
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
