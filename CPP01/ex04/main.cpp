/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:57:39 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/10 21:28:15 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

typedef std::string String;

int	main(int argc, char **argv)
{
	if (++argv && --argc != 3)
		return (1);

	// for (int i = 0; argv[i]; i++)
	// 	std::cout << argv[i] << std::endl;

	String			in_name("Makefile"); // argv[0]
	String			s1("jegerman"); // argv[1]
	String			s2("luciefer"); // argv[2]

	std::ifstream	in(in_name.data());
	// std::ifstream	in(argv[0]);
	std::ofstream	out((in_name + ".replace").c_str());
	// std::ofstream	out((String(argv[0]) + ".replace").c_str());

	// error handling
	if (in.is_open() == false || out.is_open() == false)
		return (1);


	while (in.eof() == false)
	{
		String	line;
		size_t	pos;

		std::getline(in, line);
		// do // (size_t)-1  std::cout << "Not found" << std::endl;
		// {
			// pos = line.find(s1.c_str());
			// std::cout << "pos: " << pos << std::endl;
			// std::cout << line.c_str() + pos << std::endl;
		while ((pos = line.find(s1.c_str())) != std::string::npos)
			line.erase(pos, s1.size()).insert(pos, s2);
			// line.erase(pos, s1.size()).insert(pos, argv[2]);
			// pos = line.find(s1.c_str());
			
		// } while (pos != String::npos);

		// line.erase(pos, s1.size()).insert(pos, argv[2]);
		
		out << line << std::endl;
		
	}
	in.close();
	out.close();
	
	return (0);
}
