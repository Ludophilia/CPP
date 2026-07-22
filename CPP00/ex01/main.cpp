/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/22 22:38:32 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

int	main(void)
{
	PhoneBook	phonebook;
	// int			exv;

	// 22/07: Is that really a good idea...
	try
	{
		phonebook.run();
	}
	catch (int exv)
	{
		std::cout << "\nSomething wrong occurred." << std::endl;
		return (exv);	
	}
	
	// if ((exv = phonebook.run()) > 0)
	// {
	// 	std::cout << "\nSomething wrong occurred." << std::endl;
	// 	return (exv);
	// }
	return (0);
}
