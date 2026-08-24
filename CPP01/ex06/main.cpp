/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:53:57 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/24 18:47:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int		main(int argc, char **argv)
{
	if (++argv, --argc != 1)
	{
		cerr << "usage: ./harlFilter <level>" << endl;
		return (1);
	}
	Harl().filter(*argv);
	return (0);
}
