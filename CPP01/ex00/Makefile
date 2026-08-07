# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 16:55:45 by jegerman          #+#    #+#              #
#    Updated: 2026/08/07 21:20:03 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := brainz

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -I.
# CXXFLAGS += -g -fsanitize=address

SRCS := main.cpp
SRCS += Zombie.cpp
SRCS += newZombie.cpp
SRCS += randomChump.cpp

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
