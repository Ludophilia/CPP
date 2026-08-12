/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:57:39 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/12 21:53:20 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <FakeSed.hpp>

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
