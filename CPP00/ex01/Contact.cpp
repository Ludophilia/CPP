/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:58:49 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/17 22:49:53 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

// 17/07: Please consider using an initializer... But I have to review what I
// know first. Because Contact	_contacts[CONTACT_MAX] in PhoneBook triggers
// one initializer...
void	Contact::set_contact(const String &name, const String &surname,
			const String &nickname, const String &number, const String &secret)
{
	_name = name;
	_surname = surname;
	_nickname = nickname;
	_number = number;
	_secret = secret;
}

Contact::Contact(void)
{
	std::cout << "Default initializer for testing purposes bla bla bla" << std::endl;
}

Contact::Contact(const String &name, const String &surname,
		const String &nickname, const String &number, const String &secret)
{
	std::cout << "Not default initializer bla bla bla" << std::endl;
	_name = name;
	_surname = surname;
	_nickname = nickname;
	_number = number;
	_secret = secret;
}

String	Contact::truncate_field(const String &fld, const unsigned len) const
{
	return (len > 0 && fld.size() > len ? fld.substr(0, len - 1) + "." : fld);
}

void	Contact::display_summary(int index) const
{
	std::cout	<< '|'
				<< std::setw(10) << index << '|'
				<< std::setw(10) << truncate_field(_name, 10) << '|'
				<< std::setw(10) << truncate_field(_surname, 10) << '|'
				<< std::setw(10) << truncate_field(_nickname, 10) << '|'
				<< std::endl;
}

void	Contact::display_contact(void) const
{
	std::cout	<< "First name: " << _name << '\n'
				<< "Last name: " << _surname << '\n'
				<< "Nickname: " << _nickname << '\n'
				<< "Phone number: " << _number << '\n'
				<< "Darkest secret: " << _secret << '\n'
				<< std::flush;
}
