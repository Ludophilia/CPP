/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transformer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:42:07 by jegerman          #+#    #+#             */
/*   Updated: 2026/08/07 21:45:53 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMER_H

# define TRANSFORMER_H

# include <iostream>
# include <string>
# include <fstream>
# include <stdexcept>

using std::string;

class Transformer
{
	public:
	Transformer(char *filename);
	~Transformer(void);

	void	transform(const string &find, const string &repl);

	private:
	string			_in_name;
	string			_out_name;
	std::ifstream	_in;
	std::ofstream	_out;
};

#endif
