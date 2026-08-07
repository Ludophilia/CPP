/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:27:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 20:41:44 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

using std::cout;
using std::endl;

/* const TIP: const applies to whatever is on its left, or its right if there's 
nothing. */
static void	capitalize(const char * const str)
{
	for (int j = 0; str[j]; j++)
	{
		char c = std::toupper(static_cast<unsigned char>(str[j]));
		cout << c;
	}
}

static void	megaphone(const char * const * const strs, const int len)
{
	if (len == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";	
	for (int i = 1; i < len; i++)
		capitalize(strs[i]);
	cout << endl;
}

int	main(const int argc, const char * const * const argv)
{
	megaphone(argv, argc);
	return (0);
}

/*
- ./megaphone
- ./megaphone "il " "a " "reef" ", " "il a rien compris..."
- ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
- ./megaphone "élegant comme toujours Mr. simmons"
	- [Man toupper] if c is a lowercase letter, toupper() returns its uppercase
	equivalent, IF an uppercase representation  exists in the CURRENT locale. 
*/