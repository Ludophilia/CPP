/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:53:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/19 21:58:00 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*

== DEBUG
== INFO
== WARNING
== ERROR

== default

*/
int		main(int argc, char **argv)
{
	if (++argv, --argc != 1)
	{
		cerr << "usage ./harlFiler <level>" << endl;
		return (1);
	}

	Harl	harl;

	int 	level; // Use enum

	// for (int i = 0)

	// switch (level) // integral (int, char, long...) or enum types
	// {
	// case DEBUG:
	// 	/* code */
	// 	break;
	
	// default:
	// 	break;
	// }

	// harl.complain("KAREN_CRITICAL");
	// harl.complain("DEBUG");
	// harl.complain("INFO");
	// harl.complain("WARNING");
	// harl.complain("ERROR");
	// cout << endl;
	// harl.complain("ERROR");
	// harl.complain("WARNING");
	// harl.complain("INFO");
	// harl.complain("DEBUG");
}
