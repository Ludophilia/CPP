/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/28 22:00:27 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

int	main(void)
{
	PhoneBook	phonebook;
	// int			exv;

	// std::cout << "goodbit: " << std::ios_base::goodbit << '\n';
	// std::cout << "badbit: " << std::ios_base::badbit << '\n';
	// std::cout << "eofbit: " << std::ios_base::eofbit << '\n';
	// std::cout << "failbit: " << std::ios_base::failbit << '\n';

	// return (0);

	try
	{
		phonebook.run();
	}
	// 27/07: What the hell? EVEN EOF IS CAUGHT!? I can't use this...
	catch (const std::istream::failure &e) // const std::istream::failure &e
	{
		std::cerr << "\nSomething wrong occurred: " << e.what()
				  << std::endl;
	}
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
