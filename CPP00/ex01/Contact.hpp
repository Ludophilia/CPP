/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:46:38 by jegerman          #+#    #+#             */
/*   Updated: 2026/01/29 17:08:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <string>

class Contact
{
	public:

	Contact(void);
	~Contact(void);

	// 29/01 - Unsure of the implementation...
	int	set_contact(void);
	int	get_contact(void);
	// 29/01 - set_first_name...
	// 29/01 - set_last_name...?
	
	private:

	std::string		first_name;
	std::string		last_name;
	std::string		nickname;
	std::string		phone_number;
	std::string		darkest_secret;
};

#endif
