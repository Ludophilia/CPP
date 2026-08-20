/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:53:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/20 23:57:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Level	Harl::getLevel(const string &level)
{
	const string		keys[Harl::LEVELS] =
		{"DEBUG", "INFO", "WARNING", "ERROR", "DEFAULT"};
	const Harl::Level 	vals[Harl::LEVELS] =
		{DEBUG, INFO, WARNING, ERROR, DEFAULT};

	for (int i = 0; i < Harl::LEVELS; i++)
		if (keys[i] == level)
			return (vals[i]);
	return (NONE);
}

int		main(int argc, char **argv)
{
	if (++argv, --argc != 1)
	{
		cerr << "usage: ./harlFilter <level>" << endl;
		return (1);
	}

	Harl	harl;
	const Harl::Level level = Harl::getLevel(*argv); 

	// Too hack-y...
	switch (level)
	{
		case Harl::DEBUG:
			harl.complain("DEBUG");
			// fall through
		case Harl::INFO:
			harl.complain("INFO");
			// fall through
		case Harl::WARNING:
			harl.complain("WARNING");
			// fall through
		case Harl::ERROR:
			harl.complain("ERROR");
			break ;
		default:
			harl.complain("DEFAULT");
			break ;
	}

	// WHY? Too much duplicate code.
	// const string		keys[Harl::LEVELS] =
	// 	{"DEBUG", "INFO", "WARNING", "ERROR", "DEFAULT"};

	// switch (level)
	// {
	// 	case Harl::DEBUG:
	// 		for (int i = Harl::DEBUG; i < Harl::LEVELS - 1; i++)
	// 			harl.complain(keys[i]);
	// 		break ;
	// 	case Harl::INFO:
	// 		for (int i = Harl::INFO; i < Harl::LEVELS - 1; i++)
	// 			harl.complain(keys[i]);
	// 		break ;
	// 	case Harl::WARNING:
	// 		for (int i = Harl::WARNING; i < Harl::LEVELS - 1; i++)
	// 			harl.complain(keys[i]);
	// 		break ;
	// 	case Harl::ERROR:
	// 		for (int i = Harl::ERROR; i < Harl::LEVELS - 1; i++)
	// 			harl.complain(keys[i]);
	// 		break ;
	// 	default:
	// 		harl.complain("DEFAULT");
	// 		break ;
	// }

	// inelegant
	// switch (level)
	// {
	// 	case Harl::DEBUG:
	// 		harl.complain("DEBUG");
	// 		harl.complain("INFO");
	// 		harl.complain("WARNING");
	// 		harl.complain("ERROR");
	// 		break ;
	// 	case Harl::INFO:
	// 		harl.complain("INFO");
	// 		harl.complain("WARNING");
	// 		harl.complain("ERROR");
	// 		break ;
	// 	case Harl::WARNING:
	// 		harl.complain("WARNING");
	// 		harl.complain("ERROR");
	// 		break ;
	// 	case Harl::ERROR:
	// 		harl.complain("ERROR");
	// 		break ;
	// 	default:
	// 		harl.complain("DEFAULT");
	// 		break ;
	// }


}
