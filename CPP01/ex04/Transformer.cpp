/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transformer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:31:26 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 18:50:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Transformer.h>

Transformer::Transformer(char *filename):
	_in_name(filename),
	_out_name(_in_name + ".replace"),
	_in(filename)
{
	if (this->_in.is_open() == false)
		throw std::runtime_error("'" + this->_in_name + "' cannot be opened");
	this->_out.open(_out_name.data());
	if (this->_out.is_open() == false)
		throw std::runtime_error("'" + this->_out_name + "' cannot be created");
}

Transformer::~Transformer(void)
{
	this->_in.close();
	this->_out.close();
}

void	Transformer::transform(const string &find, const string &repl)
{
	while (1)
	{
		string	line;
		size_t	pos;

		std::getline(this->_in, line);
		if (this->_in.good() == false || this->_in.eof() == true)
			break ;
		while ((pos = line.find(find.data())) != std::string::npos)
			line.erase(pos, find.size()).insert(pos, repl.data());
		this->_out << line << std::endl;
	}
}
