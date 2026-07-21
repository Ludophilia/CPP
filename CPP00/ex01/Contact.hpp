/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:46:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/21 20:39:53 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <string>

typedef std::string String;

class Contact
{
	public:

	void	set(const String *const fields);
	void	summarize(int index) const;
	void	display() const;

	private:

	String	_name;
	String	_surname;
	String	_nickname;
	String	_number;
	String	_secret;

	String	truncate(const String &field, const unsigned len) const;
};

#endif
