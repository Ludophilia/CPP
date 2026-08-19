/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 23:52:16 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/19 21:59:20 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const int		Harl::LEVELS = 4;

const string	Harl::DEBUG_MSG =
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special"
	"-ketchup burger. I really do!";

const string	Harl::INFO_MSG =
	"I cannot believe adding extra bacon costs more money. You didn't put "
	"enough bacon in my burger! If you did, I wouldn't be asking for more!";
	
const string	Harl::WARNING_MSG =
	"I think I deserve to have some extra bacon for free. I've been coming for"
	" years, whereas you started working here just last month.";

const string	Harl::ERROR_MSG =
	"This is unacceptable! I want to speak to the manager now.";

void	Harl::debug(void) const
{
	cout << "[ DEBUG ]" << '\n'
		 << Harl::DEBUG_MSG << endl;
}

void	Harl::info(void) const
{
	cout << "[ INFO ]" << '\n'
		 << Harl::INFO_MSG << endl;
}

void	Harl::warning(void) const
{
	cout << "[ WARNING ]" << '\n'
		 << Harl::WARNING_MSG << endl;
}

void	Harl::error(void) const
{
	cout << "[ ERROR ]" << '\n' 
		 << Harl::ERROR_MSG << endl;
}

// Mod
void	Harl::complain(string level) const
{
	const string	levels[Harl::LEVELS] =
		{"DEBUG", "INFO", "WARNING", "ERROR"};

	// Use getLevel???? After all, most of the logic is already here.
		
	const Logger	loggers[Harl::LEVELS] =
		{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < Harl::LEVELS; i++)
	{
		if (levels[i] == level)
		{
			(this->*loggers[i])(); 
			return ;
		}
	}
}
