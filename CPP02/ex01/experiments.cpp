/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experiments.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 22:57:30 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/14 01:00:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
    //std::cout << "3.25 ->" << (3.25 << 16) << std::endl;
    std::cout << "42 fixed -> " << (42 << 16) << std::endl; // 42 fixed -> 2752512
    std::cout << "42 fixed -> " << (42 * (1 << 16)) << std::endl; // 42 fixed -> 2752512
    std::cout << "42 int -> " << (2752512 >> 16) << std::endl; // 42 int -> 42
    std::cout << "42 int -> " << (2752512 / (1 << 16)) << std::endl; // 42 int -> 42


    std::cout << "3.25 fixed -> " << (3.25 * (1 << 16)) << std::endl; // 3.25 fixed -> 212992
    std::cout << "3 int -> " << (212992 / (1 << 16)) << std::endl; // 3 int -> 3
    std::cout << "3 int -> " << (212992 >> 16) << std::endl; // 3 int -> 3

    std::cout << "0.25 fixed -> " << (212992 & 0xFFFF) / (float)(1 << 16) << std::endl; // 0.25 fixed -> 0.25

   // std::cout << "" << (212992 & ~(1 << 16)) << std::endl;
    return 0;
}
