/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:58:49 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/20 21:30:37 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	Contact::set(const String &name, const String &surname,
		const String &nickname, const String &number, const String &secret)
{
	_name = name;
	_surname = surname;
	_nickname = nickname;
	_number = number;
	_secret = secret;
}

String	Contact::truncate(const String &fld, const unsigned len) const
{
	if (len > 0 && fld.size() > len)
		return (fld.substr(0, len - 1) + ".");
	return (fld);
}

void	Contact::summarize(int index) const
{
	std::cout	<< '|'
				<< std::setw(10) << index << '|'
				<< std::setw(10) << truncate(_name, 10) << '|'
				<< std::setw(10) << truncate(_surname, 10) << '|'
				<< std::setw(10) << truncate(_nickname, 10) << '|'
				<< std::endl;
}

void	Contact::display() const
{
	std::cout	<< "First name: " << _name << '\n'
				<< "Last name: " << _surname << '\n'
				<< "Nickname: " << _nickname << '\n'
				<< "Phone number: " << _number << '\n'
				<< "Darkest secret: " << _secret << '\n'
				<< std::flush;
}
