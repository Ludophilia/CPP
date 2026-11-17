# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 16:55:45 by jegerman          #+#    #+#              #
#    Updated: 2026/11/17 23:16:08 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := poly

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS_DIR := srcs
INCL_DIR := includes

CXXFLAGS += -I$(INCL_DIR)

SRCS := $(SRCS_DIR)/main.cpp
SRCS += $(SRCS_DIR)/Animal.cpp
SRCS += $(SRCS_DIR)/Cat.cpp
SRCS += $(SRCS_DIR)/WrongAnimal.cpp
SRCS += $(SRCS_DIR)/WrongCat.cpp
SRCS += $(SRCS_DIR)/Dog.cpp

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
