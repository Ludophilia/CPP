/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:58:49 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/10 19:47:56 by jegerman         ###   ########.fr       */
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
};

String	Contact::get_field(String field, bool trucate) const
{
	String	fdata;

	if (field == "first_name")
		fdata = this->first_name;
	else if (field == "last_name")
		fdata = this->last_name;
	else if (field == "nickname")
		fdata = this->nickname;
	else if (field == "phone_number")
		fdata = this->phone_number;
	else if (field == "darkest_secret")
		fdata = this->darkest_secret;
	else
		return (NULL);
	return (trucate && fdata.length() > 10 ? (fdata.substr(0, 9) + ".") : fdata); 	
};
