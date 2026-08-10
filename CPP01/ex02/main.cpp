/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:57:39 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/10 22:15:51 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// const TIP: A CONSTANT type (a string here), MUST have a pointer or / and
// a reference to a CONSTANT type as well, but the opposite is not true...
static void		hiThisIsBrain(const char message[])
{
	// const string			str(message); // direct initialization
	const string			str = message; // copy initialization
	const string * const	stringPTR = &str;
	// const string			&stringREF; // A reference CANNOT be reseated.
	const string			&stringREF = str;

	cout << "address str: " << &str << '\n'
		 << "address PTR: " << stringPTR << '\n'
		 << "address REF: " << &stringREF << endl;
	cout << "value str: " << str << '\n'
		 << "value PTR: " << *stringPTR << '\n'
		 << "value REF: " << stringREF << endl;
	// cout << "size str: " << sizeof(str) << '\n'
	// 	 << "size PTR: " << sizeof(stringPTR) << '\n'
	// 	 << "size REF: " << sizeof(&stringREF) << endl;
}

int	main()
{
	hiThisIsBrain("HI THIS IS BRAIN.");
	return (0);
}
