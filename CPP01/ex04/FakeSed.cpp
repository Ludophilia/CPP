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

/* Tip: RAII. It seems that the fstream objects are automatically destroyed
at the end of their lifecycle... No need for close() then in that context...
FakeSed::~FakeSed()
{
	if (_ifs.is_open())
		_ifs.close();
	if (_ofs.is_open())fil
		_ofs.close();
}*/

void	FakeSed::replace(const string &find, const string &repl)
{
	string		line;
	size_t		pos, lpos;

	while (getline(_ifs, line))
	{
		lpos = 0;
		while (find.empty() == false
				&& (pos = line.find(find, lpos)) != string::npos)
		{
			line.erase(pos, find.size())
				.insert(pos, repl);
			lpos = pos + repl.size();
		}
		_ofs << line << endl;
		line.clear();
	}
}
