/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/27 22:00:04 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

int	main(void)
{
	PhoneBook	phonebook;
	// int			exv;

	try
	{
		phonebook.run();
	}
	// 27/07: What the hell? EVEN EOF IS CAUGHT!? I can't use this...
	catch (const std::ios_base::failure &e)
	{
		std::cerr << "\nSomething wrong occurred: " << e.what()
				  << std::endl;
	}
	// 27/07: 0 is caught as well. Bad design.
	catch (const int &exv)
	{
		std::cerr << "\nSomething wrong occurred. Code: " <<  exv
			      << std::endl;
		return (exv);	
	}
	// catch exception
	
	// if ((exv = phonebook.run()) > 0)
	// {
	// 	std::cout << "\nSomething wrong occurred." << std::endl;
	// 	return (exv);
	// }
	return (0);
}
