/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 20:45:27 by jegerman          #+#    #+#             */
/*   Updated: 2026/11/19 23:53:22 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>

using std::string;
using std::exception;
using std::ostream;

// Tip: structs are public by default, while classes are private.
class Bureaucrat
{
	public:

	struct GradeTooHighException: exception
	{
		const char	*what() const throw();
	};

	struct GradeTooLowException: exception
	{
		const char	*what() const throw();
	};

	Bureaucrat();
	Bureaucrat(const string &name, unsigned grade) throw(GradeTooHighException,
		GradeTooLowException);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat();

	Bureaucrat		&operator=(const Bureaucrat &rhs);

	const string	&getName() const;
	unsigned		getGrade() const;

	void			promote() throw(GradeTooHighException);
	void			demote() throw(GradeTooLowException);

	private:

	unsigned		_grade;
	const string	_name;
};

ostream		&operator<<(ostream &lhs, const Bureaucrat &rhs);

#endif
