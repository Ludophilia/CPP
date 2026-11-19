/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 20:44:31 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/20 00:44:32 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	testGradeTooHighException()
{
	try
	{
		Bureaucrat	koumuin("Takejima", 0);
	}
	catch (const exception &e)
	{
		cerr << "Error: " << e.what() << endl;
	}
}

void	testGradeTooLowException()
{
	try
	{
		Bureaucrat	fonctionnaire("Truchot", 151);
	}
	catch (const exception &e)
	{
		cerr << "Error: " << e.what() << endl;
	}
}

void	testInvalidDemotion()
{
	try
	{
		Bureaucrat	koumuin("Takejima", 150);

		koumuin.demote();
	}
	catch (const exception &e)
	{
		cerr << "Error: " << e.what() << endl;
	}
}

void	testInvalidPromotion()
{
	try
	{
		Bureaucrat	fonctionnaire("Truchot", 1);

		fonctionnaire.promote();
	}
	catch (const exception &e)
	{
		cerr << "Error: " << e.what() << endl;
	}
}

void	testOstreamOverload()
{
	try
	{
		Bureaucrat	publicServant("Raynolds", 7),
					fonctionnaire("Levasseur", 11),
					koumuin("Kojima", 5);

		cout << publicServant << '\n'
			 << fonctionnaire << '\n'
			 << koumuin << endl;
	}
	catch (const exception &e)
	{
		cerr << "Error: " << e.what() << endl;
	}
}

int	main()
{
	testGradeTooHighException();
	testGradeTooLowException();
	testInvalidDemotion();
	testInvalidPromotion();
	testOstreamOverload();
}
