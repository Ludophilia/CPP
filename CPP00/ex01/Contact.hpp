/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:46:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/17 22:47:13 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <string>

typedef std::string String;

class Contact
{
	public:

	// 17/07: Please consider using an initializer... But I have to review 
	// what I already know first.
	Contact();
	Contact(const String &name, const String &surname, const String &nickname,
			const String &phone, const String &secret);

	void	set_contact(const String &name, const String &surname,
			const String &nickname, const String &phone, const String &secret);

	void	display_summary(int index) const;
	void	display_contact(void) const;

	private:

	String	_name;
	String	_surname;
	String	_nickname;
	String	_number;
	String	_secret;

	String	truncate_field(const String &field, const unsigned len) const;
};

#endif
