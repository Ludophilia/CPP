/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FakeSed.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:42:07 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/14 20:58:34 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FAKESED_H

# define FAKESED_H

# include <iostream>
# include <fstream>
# include <string>

using std::string;

using std::cout;
using std::cerr;
using std::endl;

using std::ios;
using std::ofstream;
using std::ifstream;

using std::getline;

class FakeSed
{
	public:

	FakeSed(const char *filename);
	~FakeSed();

	void	replace(const string &find, const string &repl);

	private:

	const string	_inm;
	const string	_onm;
	ifstream		_ifs;
	ofstream		_ofs;
};

#endif
