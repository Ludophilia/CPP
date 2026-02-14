/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:46:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/02/14 16:45:42 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <string>

typedef std::string String;

class Contact
{
	public:

	int		set_contact(String first_name, String last_name, String nickname,
			String phone_number, String darkest_secret);
	int		display_summary(int index) const;
	int		display_contact(void) const;

	private:

	String	_first_name;
	String	_last_name;
	String	_nickname;
	String	_phone_number;
	String	_darkest_secret;

	String	get_field(String field, bool trucate) const;
};

#endif
