/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:57:39 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/14 21:03:11 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <FakeSed.hpp>

// ./fakesed Makefil jegerman jgermany
// ./fakesed Makefile jegerman jgermany
// ./fakesed Makefile something nothing
// ./fakesed Makefile "" nothing
// ./fakesed Makefile "FakeSed" ""
// ./fakesed Makefile NAME NAME
// ./fakesed Makefile NAME altNAME

int	main(int argc, char **argv)
{
	if (++argv, --argc != 3)
	{
		cerr << "usage: ./fakesed <file> <to_find> <to_repl>" << endl;
		return (1);
	}
	try
	{
		FakeSed	fakesed(argv[0]);
		fakesed.replace(argv[1], argv[2]);
	}
	catch (const ios::failure& e)
	{
		cerr << "error: " << e.what() << endl;
		return (2);
	}
	return (0);
}
