/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:57:39 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/11 01:24:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Transformer.h>

int	main(int argc, char **argv)
{
	if (++argv && --argc != 3)
	{
		std::cerr << "usage: ./transformer <file> <to_find> <to_repl>";
		return (1);
	}
	try
	{
		Transformer	transformer(argv[0]);
		transformer.transform(argv[1], argv[2]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (2);
	}
	return (0);
}
