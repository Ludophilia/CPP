/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:03:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/24 18:54:00 by jegerman         ###   ########.fr       */
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

	enum Level { DEBUG = 0, INFO, WARNING, ERROR, DEFAULT };
	
	void					filter(const string &level) const;
	void					complain(const string &level) const;

	private:

	typedef void			(Harl::*Logger)(void) const;

	static const int		LEVELS;
	static const string		DEBUG_MSG;
	static const string		INFO_MSG;
	static const string		WARNING_MSG;
	static const string		ERROR_MSG;
	static const string		DEFAULT_MSG;

	Level					getLevel(const string &level) const;
	void					debug(void) const;
	void					info(void) const;
	void					warning(void) const;
	void					error(void) const;
	void					defaultf(void) const;
};

#endif
