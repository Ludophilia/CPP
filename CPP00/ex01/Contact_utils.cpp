/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_utils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:53:45 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/13 19:05:25 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

String	Contact::get_field(String field, bool trnc) const
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
	return (trnc && fdata.length() > 10 ? (fdata.substr(0, 9) + ".") : fdata); 	
}
