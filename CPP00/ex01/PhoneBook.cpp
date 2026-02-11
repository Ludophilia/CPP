/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:08:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/11 21:30:42 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void) 
{
	this->nbr = 0;
};

Contact	*PhoneBook::get_contact(int pos)
{
	if (pos < 0 || pos > CONTACT_MAX - 1)
		return (NULL);
	return (this->contacts + pos);
}

int	PhoneBook::proc_field(String uprompt, String *field) const
{
	std::cout << uprompt;
	std::cin >> (*field);
	if (std::cin.eof() || std::cin.fail())
	{
		std::cout << std::endl;
		return (-1);
	}
	return (0);
}

int	PhoneBook::add_contact(void)
{
	Contact		*new_contact;
	String		first, last, nickname, phone, secret;

	if (this->proc_field("First name: ", &first) == -1
		|| this->proc_field("Last name: ", &last) == -1
		|| this->proc_field("Nickname: ", &nickname) == -1
		|| this->proc_field("Phone: ", &phone) == -1
		|| this->proc_field("Darkest secret: ", &secret) == -1)
		return (-1);
	new_contact = this->contacts + this->nbr;
	new_contact->set_contact(first, last, nickname, phone, secret);
	this->nbr = (this->nbr == 7) ? 0 : (this->nbr + 1);
	return (0);
}

int	PhoneBook::display_summary(void)
{
	std::cout	<< "|"
				<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First name" << "|"
				<< std::setw(10) << "Last name" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < this->nbr; i++)
		this->get_contact(i)->display_summary(i);
	return (0);
}

int PhoneBook::search_contact(void)
{
	int		uin;

	if (this->nbr == 0)
		return (std::cout << "No entries :(\n", 0);
	this->display_summary();
	uin = -1;
	while (uin < 0 || uin > this->nbr - 1)
	{
		std::cout << "Which entry do you want details on? ";
		std::cin >> uin;
		if (uin < 0 || uin > this->nbr - 1)
			std::cout << "Invalid choice :(\n";
	};
	this->get_contact(uin)->display_contact();
	return (0);
}
