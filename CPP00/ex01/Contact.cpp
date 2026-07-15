/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:58:49 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/15 20:45:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

String	Contact::get_field(const String &field, bool trncate) const
{
	String	fdata;

	if (field == "first_name")
		fdata = this->_first_name;
	else if (field == "last_name")
		fdata = this->_last_name;
	else if (field == "nickname")
		fdata = this->_nickname;
	else if (field == "phone_number")
		fdata = this->_phone_number;
	else if (field == "darkest_secret")
		fdata = this->_darkest_secret;
	else
		return (NULL);
	return (trncate && fdata.length() > 10? (fdata.substr(0, 9) + "."): fdata);
}

int	Contact::set_contact(const String &name, const String &surname,
			const String &nickname, const String &phone, const String &secret)
{
	this->_first_name = name;
	this->_last_name = surname;
	this->_nickname = nickname;
	this->_phone_number = phone;
	this->_darkest_secret = secret;
	return (0);
}

// Why get_field... Why not use the 
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
