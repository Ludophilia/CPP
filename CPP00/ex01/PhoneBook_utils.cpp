/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:40:32 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/13 18:58:28 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	PhoneBook::get_size(void) const
{
	return (this->size > CONTACT_MAX ? CONTACT_MAX : this->size);
}

Contact	*PhoneBook::get_contact(int pos)
{
	if (pos < 0 || pos > CONTACT_MAX - 1)
		return (NULL);
	return (this->contacts + pos);
}

int	PhoneBook::process_field(String uprompt, String &field) const
{
	std::cout << uprompt;
	while (field.empty())
	{
		std::getline(std::cin, field);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << std::endl;
			return (-1);
		}
	}
	return (0);
}

int	PhoneBook::display_summary(void)
{
	std::cout	<< "|"
				<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First name" << "|"
				<< std::setw(10) << "Last name" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < this->get_size(); i++)
		this->get_contact(i)->display_summary(i);
	return (0);
}

int	PhoneBook::validate_input(String &uin) const
{
	const char	*str;
	int			i, sg;

	str = uin.c_str();
	i = 0;
	sg = 0;
	if (str[i] == '+' || str[i] == '-')
		(i++, sg++);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == 0 && ((sg && i >= 2) || (!sg && i >= 1)))
		return (std::atoi(str));
	return (-1);
}
