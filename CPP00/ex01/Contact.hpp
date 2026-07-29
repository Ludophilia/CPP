/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:46:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/29 22:06:51 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

using std::string;

class Contact
{
	public:

	void	set(const string fields[5]);
	void	summarize(int index) const;
	void	display() const;

	private:

	string	_name;
	string	_surname;
	string	_nickname;
	string	_number;
	string	_secret;

	string	truncate(const string &field, const unsigned len) const;
};

#endif
