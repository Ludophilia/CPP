/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transformer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:42:07 by jegerman          #+#    #+#             */
/*   Updated: 2026/03/11 00:39:45 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMER_H

# define TRANSFORMER_H

# include <iostream>
# include <string>
# include <fstream>
# include <stdexcept>

typedef std::string String;

class Transformer
{
	public:
	Transformer(char *filename);
	~Transformer(void);

	void	transform(const String &find, const String &repl);

	private:
	String			_in_name;
	String			_out_name;
	std::ifstream	_in;
	std::ofstream	_out;
};

#endif
