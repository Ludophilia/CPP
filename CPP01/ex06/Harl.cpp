/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 23:52:16 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/20 23:07:50 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const int		Harl::LEVELS = 5;

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

const string	Harl::DEFAULT_MSG =
	"Probably complaining about insignificant problems";

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

void	Harl::defaultf(void) const
{
	cout << "[ " << Harl::DEFAULT_MSG
		 << " ]" << endl;
}

void	Harl::complain(const string &level) const
{
	const Logger	loggers[Harl::LEVELS] =
		{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,
		 &Harl::defaultf};
	const Level		level_nb =
		Harl::getLevel(level);

	if (level_nb != Harl::NONE)
		(this->*loggers[level_nb])();
}

// void	Harl::complain(const string &level) const
// {
// 	const string	levels[Harl::LEVELS] =
// 		{"DEBUG", "INFO", "WARNING", "ERROR"};
// 	const Logger	loggers[Harl::LEVELS] =
// 		{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

// 	for (int i = 0; i < Harl::LEVELS; i++)
// 	{
// 		if (levels[i] == level)
// 		{
// 			(this->*loggers[i])();
// 			return ;
// 		}
// 	}
// }
