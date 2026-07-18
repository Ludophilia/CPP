/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:46:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/18 17:46:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <string>

typedef std::string String;

class Contact
{
	public:

	void	set(const String &name, const String &surname,
			const String &nickname, const String &number, const String &secret);
	void	summarize(int index) const;
	void	display() const;

	private:

	// 18/07: Trace the lifecycle of those strings right here...
	// Do I just init them once when the Contact is created and then throw
	// them away and replace them by something else?
	String	_name;
	String	_surname;
	String	_nickname;
	String	_number;
	String	_secret;

	String	truncate(const String &field, const unsigned len) const;
};

#endif
