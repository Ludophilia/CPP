/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:51 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/27 00:07:07 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int	main()
{
	try
	{
		PhoneBook	phonebook;

		phonebook.run();
	}
	catch (const istream::failure &e)
	{
		cerr	  << "Something wrong occurred: " 
				  << e.what()
				  << endl;
		return (1);
	}
	return (0);
}
