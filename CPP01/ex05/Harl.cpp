/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 23:52:16 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/18 23:02:13 by jegerman         ###   ########.fr       */
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

void	Harl::debug(void)
{
	cout << Harl::DEBUG_MSG << endl;
}

void	Harl::info(void)
{
	cout << Harl::INFO_MSG << endl;
}

void	Harl::warning(void)
{
	cout << Harl::WARNING_MSG << endl;
}
void	Harl::error(void)
{
	cout << Harl::ERROR_MSG << endl;
}

void	Harl::complain(string level)
{
	const string	levels[] =
		{"DEBUG", "INFO", "WARNING", "ERROR"};
	const Logger	logs[] =
		{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	// const Logger	logs[] =
	// 	{&debug, &info, &warning, &error};
		
	// ........ We're not done yet.
	// for (int i = 0; i < Harl::LEVELS; i++)
	// {
	// 	if (Harl::levels[i] == level)
	// 	{
	// 		(this->*loggers[i])(); 
	// 		return ;
	// 	}
	// }
}
