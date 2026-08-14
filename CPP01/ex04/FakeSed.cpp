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

FakeSed::FakeSed(const char *filename):
	_inm(filename),
	_onm(_inm + ".replace"),
	_ifs(_inm.c_str())
{
	if (!_ifs)
		throw ifstream::failure("'" + _inm + "' cannot be opened");
	_ofs.open(_onm.c_str());
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
	string		line;
	size_t		pos, lpos;

	while (getline(_ifs, line))
	{
		lpos = 0;
		while (find.empty() == false
				&& (pos = line.find(find.c_str(), lpos)) != string::npos)
		{
			line.erase(pos, find.size())
				.insert(pos, repl.c_str());
			lpos = pos + repl.size();
		}
		_ofs << line << endl;
		line.clear();
	}
}
