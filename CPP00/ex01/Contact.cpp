/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:58:49 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/16 23:13:10 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

// 16/07: BRUV, WTH? Use an initializer for f sakes... 
void	Contact::set_contact(const String &name, const String &surname,
			const String &nickname, const String &phone, const String &secret)
{
	_first_name = name;
	_last_name = surname;
	_nickname = nickname;
	_phone_number = phone;
	_darkest_secret = secret;
}

// 15/07: Do we really need that interface? Why not just create a trucate function
// and just pass the attribute directly?
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


// 15/07: Why get_field... Why not use the member attributes directly instead of a
// getter... 
void	Contact::display_summary(int index) const
{
	std::cout	<< "|"
				<< std::setw(10) << index << "|"
				<< std::setw(10) << get_field("first_name", true) << "|"
				<< std::setw(10) << get_field("last_name", true) << "|"
				<< std::setw(10) << get_field("nickname", true) << "|"
				<< std::endl;	
}

void	Contact::display_contact(void) const
{
	std::cout	<< "First name: " << _first_name << '\n'
				<< "Last name: " << _last_name << '\n'
				<< "Nickname: " << _nickname << '\n'
				<< "Phone number: " << _phone_number << '\n'
				<< "Darkest secret: " << _darkest_secret << '\n'
				<< std::flush;
}
