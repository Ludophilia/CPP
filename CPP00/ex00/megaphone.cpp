/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:27:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/01/28 18:52:27 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	megaphone(const char *str)
{
	for (int j = 0; str[j]; j++)
	{
		char c = std::toupper(static_cast<unsigned char>(str[j]));
		std::cout << c;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; argv[i]; i++)
		megaphone(argv[i]);
	std::cout << std::endl;
	return (0);
}
