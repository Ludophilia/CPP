/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:27:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/16 21:37:17 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/* Why is that necessary to cast str[j] to unsigned char?

- Not every character neatly fits into the original ASCII. ASCII has 
been extended and other encoding standards exist. So it's capital not to
ignore the 128-255 part...
	- https://en.wikipedia.org/wiki/ASCII
	- https://en.wikipedia.org/wiki/Extended_ASCII
	- https://en.wikipedia.org/wiki/ISO/IEC_8859-1
	- https://en.wikipedia.org/wiki/UTF-8

- [Man toupper] If c is neither an unsigned char value nor EOF,
the behavior of these functions is undefined. */
void	capitalize(const char *str)
{
	for (int j = 0; str[j]; j++)
	{
		char c = std::toupper(static_cast<unsigned char>(str[j]));
		std::cout << c;
	}
}

void	megaphone(char **strs, int len)
{
	if (len == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";	
	for (int i = 1; i < len; i++)
		capitalize(strs[i]);
	std::cout << std::endl;
}

/*
- ./megaphone
- ./megaphone "il " "a " "reef" ", " "il n'a rien compris..."
- ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
- ./megaphone "élegant comme toujours Mr. simmons"
	- [Man toupper] if c is a lowercase letter, toupper() returns its uppercase
	equivalent, IF an uppercase representation  exists in the CURRENT locale. 
*/
int	main(int argc, char **argv)
{
	megaphone(argv, argc);
	return (0);
}
