/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:58:49 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/13 18:57:23 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	Contact::set_contact(String name, String surname, String nickname,
	String phone, String secret)
{
	this->first_name = name;
	this->last_name = surname;
	this->nickname = nickname;
	this->phone_number = phone;
	this->darkest_secret = secret;
	return (0);
}

int	Contact::display_summary(int index) const
{
	std::cout	<< "|"
				<< std::setw(10) << index << "|"
				<< std::setw(10) << this->get_field("first_name", true) << "|"
				<< std::setw(10) << this->get_field("last_name", true) << "|"
				<< std::setw(10) << this->get_field("nickname", true) << "|"
				<< std::endl;
	return (0);
}

int	Contact::display_contact(void) const
{
	std::cout	<< "First name: "
				<< this->get_field("first_name", false) << "\n"
				<< "Last name: "
				<< this->get_field("last_name", false) << "\n"
				<< "Nickname: "
				<< this->get_field("nickname", false) << "\n"
				<< "Phone number: "
				<< this->get_field("phone_number", false) << "\n"
				<< "Darkest secret: "
				<< this->get_field("darkest_secret", false) << "\n";
	return (0);
}
