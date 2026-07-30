/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/31 00:31:58 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

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
		return (1);
	}
	return (0);
}
