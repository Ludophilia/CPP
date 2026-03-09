/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:57:39 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/05 21:29:38 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str("HI THIS IS BRAIN.");
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "address str: " << &str << std::endl
			  << "address PTR: " << stringPTR << std::endl
			  << "address REF: " << &stringREF << std::endl;
	std::cout << "value str: " << str << std::endl
			  << "value PTR: " << *stringPTR << std::endl
			  << "value REF: " << stringREF << std::endl;
	// std::cout << "size str: " << sizeof(str) << std::endl
	// 		  << "size PTR: " << sizeof(stringPTR) << std::endl
	// 		  << "size REF: " << sizeof(&stringREF) << std::endl;
	return (0);
}
