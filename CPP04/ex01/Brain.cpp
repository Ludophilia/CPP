/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:55:34 by jegerman          #+#    #+#             */
/*   Updated: 2026/10/30 22:32:23 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	cout << "Brain default constructor called" << endl;
}

Brain::Brain(const Brain &src)
{
	cout << "Brain copy constructor called" << endl;
	*this = src;
}

Brain::~Brain()
{
	cout << "Brain default destructor called" << endl;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
		for (int i = 0; i < Brain::SIZE; i++)
			ideas[i] = rhs.ideas[i];
	return (*this);
}
