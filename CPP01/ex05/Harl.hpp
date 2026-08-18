/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:03:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/18 22:54:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP

# define HARL_HPP

# include <iostream>
# include <string>

using	std::string;
using	std::cout;
using	std::endl;

// using ll = long long; // c++ 11 man.... Wont work.
// typedef long long ll;

class Harl
{
	public:

	// typedef void	(Harl::*Hlgr_t)(void);
	// typedef void	(*lgr_t)(void);
	// typedef void	(*LOGGER)(void);
	// typedef void	(*Logger)(void);
	// typedef void	(Harl::*Logger)(void);
	typedef void	(Harl::*Logger)(void);

	void	complain(string level);

	private:

	static const int		LEVELS;
	static const string		DEBUG_MSG;
	static const string		INFO_MSG;
	static const string 	WARNING_MSG;
	static const string 	ERROR_MSG;

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

// typedef void	(Harl::*Harlloggers_t)(void);

// typedef void	(Harl::*hlgr_t)(void);

// typedef void	(Harl::*HLgr_t)(void); // What if... We put the typedef inside the class?

#endif
