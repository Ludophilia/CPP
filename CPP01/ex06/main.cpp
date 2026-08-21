/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:53:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/21 22:19:45 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static void	harlFilter(const string &level_arg)
{
	Harl				harl;
	const Harl::Level 	level = Harl::getLevel(level_arg); 

	switch (level)
	{
		case Harl::DEBUG:
			harl.complain("DEBUG");
			/* fallthrough */ // C++ 17 has [[fallthrough]]; built-in !!
		case Harl::INFO:
			harl.complain("INFO");
			/* fallthrough */
		case Harl::WARNING:
			harl.complain("WARNING");
			/* fallthrough */
		case Harl::ERROR:
			harl.complain("ERROR");
			break ;
		default:
			harl.complain("DEFAULT");
			break ;
	}
}

int		main(int argc, char **argv)
{
	if (++argv, --argc != 1)
	{
		cerr << "usage: ./harlFilter <level>" << endl;
		return (1);
	}
	harlFilter(*argv);
	return (0);
}
