# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 16:55:45 by jegerman          #+#    #+#              #
#    Updated: 2026/11/18 22:56:49 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := violence

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
# CXXFLAGS += -g -fsanitize=address

SRCS_DIR := srcs
INCL_DIR := includes

CXXFLAGS += -I$(INCL_DIR)

SRCS := $(SRCS_DIR)/main.cpp
SRCS += $(SRCS_DIR)/Weapon.cpp
SRCS += $(SRCS_DIR)/HumanA.cpp
SRCS += $(SRCS_DIR)/HumanB.cpp

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
