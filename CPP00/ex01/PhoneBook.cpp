/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:08:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/13 19:12:19 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void) 
{
	this->pos = 0;
	this->size = 0;
}

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
	new_contact = this->contacts + this->pos;
	new_contact->set_contact(first, last, nickname, phone, secret);
	this->pos = (this->pos == 7) ? 0 : (this->pos + 1);
	this->size++;
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
