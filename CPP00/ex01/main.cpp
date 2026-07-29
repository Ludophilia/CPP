/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/29 22:18:57 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

// Almost done x01, after more than a week of improvements.

// Learned more about namespaces and the using keyword, that I thought 
// forbidden which resulted in some welcomed additional improvements like
// the use of string instead of String to use a str...

// Improved the inclusions in the header to comply with the rule: "You should 
// be able to use each of your headers independently from others."

int	main(void)
{
	try
	{
		PhoneBook	phonebook;

		phonebook.run();
	}
	catch (const std::istream::failure &e)
	{
		std::cerr << "Something wrong occurred: " 
				  << e.what()
				  << std::endl;
	}
	return (0);
}
