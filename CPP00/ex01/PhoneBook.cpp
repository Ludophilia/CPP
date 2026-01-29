/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:08:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/01/29 18:47:24 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "[" << this << "]" << "PhoneBook created." << std::endl;
	this->nbr = 0;
};

PhoneBook::~PhoneBook(void)
{
	// std::cout << "[" << this << "]" << "PhoneBook destroyed." << std::endl;
};

int	PhoneBook::add_contact(void)
{
	Contact	*contact;
	// 29/01

	// WSBD?

	// = Add a contact?
	// How?
	// Select contact in contacts based on nbr
	// 

	contact = this->contacts + this->nbr;

	std::cout << "contact #" << contact << std::endl;

	// Incrementation logic.
	this->nbr = (this->nbr == 7) ? 0 : (this->nbr + 1);
	return (0);
}

int	PhoneBook::print_contacts(void)
{
	return (0);
}
