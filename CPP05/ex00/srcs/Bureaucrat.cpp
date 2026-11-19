/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 22:48:10 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/20 00:44:51 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's rank is higher than 1!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's rank is lower than 150!");
}

Bureaucrat::Bureaucrat()
	: _name("unknown"), _grade(150) {}

Bureaucrat::Bureaucrat(const string &name, unsigned grade)
	throw(GradeTooHighException, GradeTooLowException)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		_grade = rhs._grade;
	return (*this);
}

const string	&Bureaucrat::getName() const
{
	return (_name);
}

unsigned	Bureaucrat::getGrade() const
{
	return (_grade);
}

void		Bureaucrat::promote() throw(GradeTooHighException)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void		Bureaucrat::demote() throw(GradeTooLowException)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

ostream		&operator<<(ostream &lhs, const Bureaucrat &rhs)
{
	return (lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade()
			    << ".");
}
