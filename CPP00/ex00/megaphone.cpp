/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:27:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/03 17:29:25 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

using std::cout;
using std::endl;

void	capitalize(const char *str)
{
	for (int j = 0; str[j]; j++)
	{
		char c = std::toupper(static_cast<unsigned char>(str[j]));
		cout << c;
	}
}

void	megaphone(const char * const *strs, const int len)
{
	if (len == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";	
	for (int i = 1; i < len; i++)
		capitalize(strs[i]);
	cout << endl;
}

int	main(const int argc, const char * const *argv)
{
	megaphone(argv, argc);
	return (0);
}

/*
- ./megaphone
- ./megaphone "il " "a " "reef" ", " "il n'a rien compris..."
- ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
- ./megaphone "élegant comme toujours Mr. simmons"
	- [Man toupper] if c is a lowercase letter, toupper() returns its uppercase
	equivalent, IF an uppercase representation  exists in the CURRENT locale. 
*/