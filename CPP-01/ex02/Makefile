# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 15:06:49 by lebarbos          #+#    #+#              #
#    Updated: 2024/08/03 15:19:21 by lebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = string

CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98

# Diretórios

SOURCES = main.cpp 
OBJS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re