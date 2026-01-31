/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:08:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/01/31 18:36:56 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void) 
{
	this->nbr = 0;
};

int	PhoneBook::proc_field(std::string uprompt, std::string *field) const
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

	std::cout << "[Contact #" << this->nbr + 1 << "]\n";
	if (this->proc_field("\tfirst name: ", &first) == -1
		|| this->proc_field("\tlast name: ", &last) == -1
		|| this->proc_field("\tnickname: ", &nickname) == -1
		|| this->proc_field("\tphone: ", &phone) == -1
		|| this->proc_field("\tdarkest secret: ", &secret) == -1)
		return (-1);
	new_contact = this->contacts + this->nbr;
	new_contact->set_contact(first, last, nickname, phone, secret);
	this->nbr = (this->nbr == 7) ? 0 : (this->nbr + 1);
	return (0);
}

int	PhoneBook::print_contacts(void)
{
	return (0);
}
