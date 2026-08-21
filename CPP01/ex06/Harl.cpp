/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 23:52:16 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/21 22:12:01 by jegerman         ###   ########.fr       */
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

const string	Harl::DEFAULT_MSG =
	"Probably complaining about insignificant problems";

Harl::Level	Harl::getLevel(const string &level)
{
	const string		keys[Harl::LEVELS] =
		{"DEBUG", "INFO", "WARNING", "ERROR"};
	const Harl::Level 	vals[Harl::LEVELS] =
		{DEBUG, INFO, WARNING, ERROR};

	for (int i = 0; i < Harl::LEVELS; i++)
		if (keys[i] == level)
			return (vals[i]);
	return (DEFAULT);
}

void	Harl::debug(void) const
{
	cout << "[ DEBUG ]" << '\n'
		 << Harl::DEBUG_MSG << '\n'
		 << endl;
}

void	Harl::info(void) const
{
	cout << "[ INFO ]" << '\n'
		 << Harl::INFO_MSG << '\n'
		 << endl;
}

void	Harl::warning(void) const
{
	cout << "[ WARNING ]" << '\n'
		 << Harl::WARNING_MSG << '\n'
		 << endl;
}

void	Harl::error(void) const
{
	cout << "[ ERROR ]" << '\n' 
		 << Harl::ERROR_MSG << '\n'
		 << endl;
}

void	Harl::defaultf(void) const
{
	cout << "[ " << Harl::DEFAULT_MSG
		 << " ]" << endl;
}

void	Harl::complain(const string &level) const
{
	const Logger	loggers[Harl::LEVELS + 1] =
		{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,
		 &Harl::defaultf};
	const Level		level_nb =
		Harl::getLevel(level);

	(this->*loggers[level_nb])();
}
