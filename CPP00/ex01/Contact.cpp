/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:58:49 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/27 00:03:44 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set(const string fields[5])
{
	_name = fields[0];
	_surname = fields[1];
	_nickname = fields[2];
	_number = fields[3];
	_secret = fields[4];
}

string	Contact::truncate(const string &fld, const unsigned len) const
{
	if (len > 0 && fld.size() > len)
		return (fld.substr(0, len - 1) + ".");
	return (fld);
}

void	Contact::summarize(int index) const
{
	cout	<< '|'
			<< setw(10) << index << '|'
			<< setw(10) << truncate(_name, 10) << '|'
			<< setw(10) << truncate(_surname, 10) << '|'
			<< setw(10) << truncate(_nickname, 10) << '|'
			<< endl;
}

void	Contact::display() const
{
	cout	<< "First name: " << _name << '\n'
			<< "Last name: " << _surname << '\n'
			<< "Nickname: " << _nickname << '\n'
			<< "Phone number: " << _number << '\n'
			<< "Darkest secret: " << _secret << '\n'
			<< flush;
}
