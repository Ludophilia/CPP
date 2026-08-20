/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:03:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/20 23:55:17 by jegerman         ###   ########.fr       */
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

	enum Level { NONE = -1, DEBUG, INFO, WARNING, ERROR, DEFAULT };
	
	static const int		LEVELS;
	static Level			getLevel(const string &level);

	void					complain(const string &level) const;

	private:

	typedef void	(Harl::*Logger)(void) const;

	static const string		DEBUG_MSG;
	static const string		INFO_MSG;
	static const string 	WARNING_MSG;
	static const string 	ERROR_MSG;
	static const string 	DEFAULT_MSG;

	void	debug(void) const;
	void	info(void) const;
	void	warning(void) const;
	void	error(void) const;
	void	defaultf(void) const;
};

#endif
