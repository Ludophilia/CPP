/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 21:32:38 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

int	main()
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
