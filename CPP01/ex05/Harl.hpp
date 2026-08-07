/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:03:35 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 18:50:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP

# define HARL_HPP

# include <iostream>
# include <string>

# define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple"\
"-pickle-special-ketchup burger. I really do!"
# define INFO_MSG "I cannot believe adding extra bacon costs more money. " \
"You didn’t put enough bacon in my burger! If you did, I wouldn’t " \
"be asking for more!"
# define WARNING_MSG "I think I deserve to have some extra bacon for free." \
" I’ve been coming for years, whereas you started working here just last month."
# define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

typedef std::string string;

class Harl
{
	public:

	void	complain(string level);

	private:

	static const char	*levels[];

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif
