# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 16:55:45 by jegerman          #+#    #+#              #
#    Updated: 2026/10/28 16:36:21 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := diamond

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -Wshadow -std=c++98 -I.

SRCS := main.cpp
SRCS += ClapTrap.cpp
SRCS += ScavTrap.cpp
SRCS += FragTrap.cpp
SRCS += DiamondTrap.cpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SILENT: clean fclean
.PHONY: all clean fclean re
