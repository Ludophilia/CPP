/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fakesed.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:31:26 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/12 19:43:40 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <FakeSed.hpp>

FakeSed::FakeSed(const string &filename):
	_inm(filename),
	_onm(_inm + ".replace"),
	_ifs(_inm.c_str()),
	_ofs(_onm.c_str())
{
	if (!_ifs)
		throw ifstream::failure("'" + _inm + "' cannot be opened");
	if (!_ofs)
		throw ofstream::failure("'" + _onm + "' cannot be created");
}

FakeSed::~FakeSed()
{
	_ifs.close();
	_ofs.close();
}

void	FakeSed::replace(const string &find, const string &repl)
{
	string	line;
	size_t	pos;

	while (1)
	{
		line.clear();
		if (!std::getline(_ifs, line))
			break ;

		// Yeah... Let's see how much I can improve the two following lines next...
		while ((pos = line.find(find.data())) != string::npos)
			line.erase(pos, find.size()).insert(pos, repl.data());


		_ofs << line << endl;
	}
}
