/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:03:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/25 18:57:48 by jegerman         ###   ########.fr       */
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

	enum LevelID { DEBUG = 0, INFO, WARNING, ERROR, DEFAULT };
	
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

	LevelID					getLevelID(const string &level) const;
	void					debug() const;
	void					info() const;
	void					warning() const;
	void					error() const;
	void					defaultf() const;
};

#endif
