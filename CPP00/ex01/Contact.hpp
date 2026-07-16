/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:46:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/16 23:15:07 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <string>

typedef std::string String;

class Contact
{
	public:

	// 16/07: Can't we use initializers in that assignment?
	void	set_contact(const String &name, const String &surname,
			const String &nickname, const String &phone, const String &secret);


			
	void	display_summary(int index) const;
	void	display_contact(void) const;

	private:

	String	_first_name;
	String	_last_name;
	String	_nickname;
	String	_phone_number;
	String	_darkest_secret;

	// 16/07: No no no no... 
	String	get_field(const String &field, bool trucate) const;
};

#endif
