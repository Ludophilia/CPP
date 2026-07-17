/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:08:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/17 22:33:46 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void) 
{
	this->_pos = 0;
	this->_size = 0;
}

// 17/07: Returning -1 is not proper C++...
int	PhoneBook::add_contact(void)
{
	Contact		*new_contact;
	String		first, last, nickname, phone, secret;

	if (this->process_field("First name: ", first) == -1
		|| this->process_field("Last name: ", last) == -1
		|| this->process_field("Nickname: ", nickname) == -1
		|| this->process_field("Phone: ", phone) == -1
		|| this->process_field("Darkest secret: ", secret) == -1)
		return (-1);
	new_contact = this->_contacts + this->_pos;
	new_contact->set_contact(first, last, nickname, phone, secret);
	this->_pos = (this->_pos == 7) ? 0 : (this->_pos + 1);
	this->_size++;
	return (0);
}

int PhoneBook::search_contact(void)
{
	int		entry;
	String	uin;

	if (this->get_size() == 0)
		return (std::cout << "No entries :(\n", 0);
	this->display_summary();
	entry = -1;
	while (entry < 0 || entry > this->get_size() - 1)
	{
		std::cout << "Which entry do you want details on? ";
		std::getline(std::cin, uin);
		if (std::cin.eof() || std::cin.fail())
			return (std::cout << "\nSomething wrong occured :/\n", -1);
		entry = this->validate_input(uin);
		if (entry < 0 || entry > this->get_size() - 1)
			std::cout << "Invalid input :(\n";
	};
	this->get_contact(entry)->display_contact();
	return (0);
}

int	PhoneBook::get_size(void) const
{
	return (this->_size > CONTACT_MAX ? CONTACT_MAX : this->_size);
}

Contact	*PhoneBook::get_contact(int pos)
{
	if (pos < 0 || pos > CONTACT_MAX - 1)
		return (NULL);
	return (this->_contacts + pos);
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

int	PhoneBook::display_summary(void)
{
	std::cout	<< "|"
				<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First name" << "|"
				<< std::setw(10) << "Last name" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < this->get_size(); i++)
		this->get_contact(i)->display_summary(i);
	return (0);
}

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
