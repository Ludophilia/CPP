# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 16:55:45 by jegerman          #+#    #+#              #
#    Updated: 2026/03/23 20:50:13 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := poly

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -I.

SRCS := main.cpp
SRCS += Animal.cpp
SRCS += Cat.cpp
SRCS += Dog.cpp
SRCS += Brain.cpp

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
