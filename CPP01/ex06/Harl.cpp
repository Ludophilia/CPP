/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 23:52:16 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/25 19:42:15 by jegerman         ###   ########.fr       */
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

void	Harl::debug() const
{
	cout << "[ DEBUG ]" << '\n'
		 << Harl::DEBUG_MSG << '\n'
		 << endl;
}

void	Harl::info() const
{
	cout << "[ INFO ]" << '\n'
		 << Harl::INFO_MSG << '\n'
		 << endl;
}

void	Harl::warning() const
{
	cout << "[ WARNING ]" << '\n'
		 << Harl::WARNING_MSG << '\n'
		 << endl;
}

void	Harl::error() const
{
	cout << "[ ERROR ]" << '\n' 
		 << Harl::ERROR_MSG << '\n'
		 << endl;
}

void	Harl::defaultf() const
{
	cout << "[ "
		 << Harl::DEFAULT_MSG << " ]"
		 << endl;
}

Harl::LevelID	Harl::getLevelID(const string &level) const
{
	const string		keys[Harl::LEVELS] =
		{"DEBUG", "INFO", "WARNING", "ERROR"};
	const LevelID 	vals[Harl::LEVELS] =
		{DEBUG, INFO, WARNING, ERROR};

	for (int i = 0; i < Harl::LEVELS; i++)
		if (keys[i] == level)
			return (vals[i]);
	return (DEFAULT);
}

void	Harl::complain(const string &level) const
{
	const Logger	loggers[Harl::LEVELS + 1] =
		{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,
		 &Harl::defaultf};
	const LevelID	levelID = getLevelID(level);

	(this->*loggers[levelID])();
}

void	Harl::filter(const string &level) const
{
	const LevelID 	levelID = getLevelID(level);

	switch (levelID)
	{
		case DEBUG:
			complain("DEBUG");
			/* fallthrough */ // C++ 17 has [[fallthrough]]; built-in !!
		case INFO:
			complain("INFO");
			/* fallthrough */
		case WARNING:
			complain("WARNING");
			/* fallthrough */
		case ERROR:
			complain("ERROR");
			break ;
		default:
			complain("DEFAULT");
			break ;
	}
}
