/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:57:39 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/10 01:45:40 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// for (int i = 0; argv[i]; i++)
	// 	std::cout << argv[i] << std::endl;

	// open file? (Huge source of errors)


	std::ifstream	in("Makefile");
	std::string		out_name("Makefile");
	std::ofstream	out;

	out_name += ".replace"; 
	// error handling
	out.open(out_name.c_str());

	if (in.is_open() == false
		|| out.is_open() == false)
		return (1);


	while (in.eof() == false)
	{
		std::string s;
		// char	s[128];
	
		std::getline(in, s);
		// in.read(s, 127);

		out << s << std::endl;
		
	}
	in.close();





	


	// create new file replace

	// copy 
	
	return (0);
}
