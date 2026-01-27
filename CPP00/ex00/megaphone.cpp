/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:27:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/01/27 19:00:34 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	std::cout << "Ca marche" << std::endl;
	std::cout << "\targc = " << argc << std::endl;
	std::cout << "\targv starts with " << *argv << std::endl;
}
