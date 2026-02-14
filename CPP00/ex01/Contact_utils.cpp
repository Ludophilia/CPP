/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_utils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:53:45 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/14 16:46:00 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

String	Contact::get_field(String field, bool trnc) const
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
	return (trnc && fdata.length() > 10 ? (fdata.substr(0, 9) + ".") : fdata); 	
}
