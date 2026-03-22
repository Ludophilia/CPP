/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:55:34 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/22 23:00:42 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Default Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
		for (int i = 0; i < Brain::size; i++)
			this->ideas[i] = rhs.ideas[i];
	return (*this);
}
