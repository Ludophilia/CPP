/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:30:29 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/30 23:03:51 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP

# define BRAIN_HPP

# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

class Brain
{
	public:

	Brain();
	Brain(const Brain &src);
	~Brain();

	Brain	&operator=(const Brain &rhs);

	private:

	static const int 	SIZE = 100;
	string				ideas[SIZE];
};

#endif
