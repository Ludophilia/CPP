/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 19:28:41 by jegerman          #+#    #+#             */
/*   Updated: 2026/07/24 23:01:03 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>

// 24/07: Might be useful for modules after CPP04, especially CPP05...

// References: 
//		- https://www.geeksforgeeks.org/cpp/exception-handling-c/
// 		- https://cplusplus.com/reference/exception/exception/
//		- https://www.youtube.com/watch?v=5nCXSDv6e4I (<= Damn he's good)

class MyException: public std::exception {

	public:
		MyException() {}

		virtual const char	*what() const throw() {
			return "My very basic exception has been caught";
		}
};

class MyObject {
	public:
		MyObject(int id): _id(id) {
			std::cout << "Object #" << _id << " created\n";
		}
		~MyObject() {
			std::cout << "Object #" << _id << " destroyed\n";
		}
	private:
	const int	_id;
};

void d() {
	std::string		str("Ayoooo! Bro thinks is on the team.");

	// throw std::runtime_error("Bro wtf?");
	// throw std::exception();
	int	*nbrs = new int[424242424242]; // or throw std::bad_alloc();
	// throw "I AM ERROR.";
	// throw 42;
	// throw 42.21;
	// throw str;
	throw MyException();
	std::cout << "This will NEVER be printed (4)\n";
}

void c() {
	d();
	std::cout << "This will NEVER be printed (3)\n";
}

void b() {
	c();
	std::cout << "This will NEVER be printed (2)\n";
}

void a() {
	b();
	std::cout << "This will NEVER be printed (1)\n";
}

int main() {
	MyObject	object0(0);

	// a(); // terminate called after throwing an instance of
	try {
		MyObject	object1(1); // Ohoh, creating an obj in a try block
		// affect construction + construction lifecycle... Seems logical.
		a(); // An exception propagates up to the main caller
	}
	catch (const char* msg) {
		std::cerr << "Error (char *): " << msg;
	}
	catch (const int nb) {
		std::cerr << "Error (nb): " << nb;
	}
	catch (const std::string &str) {
		std::cerr << "Error (string): " << str;
	}
	catch (const std::exception &e) {
		std::cerr << "Error (exception): " << e.what(); 
	}
	catch (...) {
		std::cerr << "Error (generic)";  // considering adding a generic 
		// block... Memory leaks can occur if the program terminates abruptly.
	}
	std::cout << std::endl;
	std::cout << "This WILL be printed if the exception is caught (0)\n";
}
