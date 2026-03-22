/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:30:29 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/22 23:01:02 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP

# define BRAIN_HPP

# include <iostream>
# include <string>

typedef std::string String;

class Brain
{
	public:

	Brain(void);
	Brain(const Brain &src);
	~Brain(void);
	Brain	&operator=(const Brain &rhs);

	private:

	static const int 	size = 100;
	String				ideas[size];
};

#endif
