/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifstream.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:49:17 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/15 19:46:15 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;
using std::flush;
using std::string;

int	main()
{
	const string		filename = "file";
	ifstream			ifs(filename.c_str());
	int					nb1, nb2, nb3;

	if (!ifs)
	{
		cerr << "Unable to open file `" << filename << "'" << endl;
		return (1);
	}
	// ifs >> nb1;
	// ifs >> nb2;
	// ifs >> nb3;

	// OR chained like that...  >> stops after a whitespace anyway.
	// ifs >> nb1 >> nb2 >> nb3;

	// OR multiline, capitalizing on the fact ifs will return false
	// at the end of the file...
	while (ifs >> nb1 >> nb2 >> nb3)
		cout << nb1 << ' ' << nb2 << ' ' << nb3 << endl;

	// No leaking fds at the end... It seems that the fstream 
	// objects are automatically destroyed at the end of their lifecycle...
	cout << "(ifs is still opened: " << (ifs.is_open()? "yes)" : "no)")
		 << endl;
	return (0);
}
