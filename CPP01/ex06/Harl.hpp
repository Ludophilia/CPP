/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:03:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/19 21:56:40 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP

# define HARL_HPP

# include <iostream>
# include <string>

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;

class Harl
{
	public:

	typedef void	(Harl::*Logger)(void) const;

	// How about adding enum types in... here for those levels.
	// Yeah, nested enums... But How does it work exactly?

	enum levels
	{
		DEBUG = 1,
		INFO,
		WARNING,
		ERROR
	};
	
	static int	getLevel(char *level); // returns an enum to use for switch and
	static int	getLevel(string level); // Polymorphism WOW 💫 

	void	complain(string level) const; // That const shi is unreal I swear to the big G

	private:

	static const int		LEVELS;
	static const string		DEBUG_MSG;
	static const string		INFO_MSG;
	static const string 	WARNING_MSG;
	static const string 	ERROR_MSG;

	void	debug(void) const;
	void	info(void) const;
	void	warning(void) const;
	void	error(void) const;
};

#endif
