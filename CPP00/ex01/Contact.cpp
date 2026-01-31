/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:58:49 by jegerman          #+#    #+#             */
/*   Updated: 2026/01/31 15:32:16 by jegerman         ###   ########.fr       */
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

int	Contact::get_contact(void) const
{
	return (0);
};
