/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:46:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/15 23:04:02 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <string>

typedef std::string String;

class Contact
{
	public:

	// String or const String &... Why do we need to even That's the kind of things I had to
	// relearn 
	int		set_contact(const String &name, const String &surname,
			const String &nickname, const String &phone, const String &secret);
	int		display_summary(int index) const;
	int		display_contact(void) const;

	private:

	String	_first_name;
	String	_last_name;
	String	_nickname;
	String	_phone_number;
	String	_darkest_secret;

	String	get_field(const String &field, bool trucate) const;
};

#endif
