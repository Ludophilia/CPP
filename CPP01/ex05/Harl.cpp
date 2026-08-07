/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 23:52:16 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 18:50:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const char	*Harl::levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", 0};

void	Harl::debug(void)
{
	std::cout << DEBUG_MSG << std::endl;
}

void	Harl::info(void)
{
	std::cout << INFO_MSG << std::endl;
}				

void	Harl::warning(void)
{
	std::cout << WARNING_MSG << std::endl;
}

void	Harl::error(void)
{
	std::cout << ERROR_MSG << std::endl;
}

void	Harl::complain(string level)
{
	void	(Harl::*loggers[])(void) = {&Harl::debug, &Harl::info,
			&Harl::warning, &Harl::error};

	for (int i = 0; Harl::levels[i]; i++)
	{
		if (Harl::levels[i] == level)
		{
			(this->*loggers[i])();
			return ;
		}
	}
}
