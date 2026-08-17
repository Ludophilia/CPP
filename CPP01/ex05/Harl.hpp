/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:03:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/17 21:55:04 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP

# define HARL_HPP

# include <iostream>
# include <string>

using	std::string;
using	std::cout;
using	std::endl;

typedef void	(Harl::*logf_t[])(void); // ..... No. Can't `using` help here?

class Harl
{
	public:

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

#endif
