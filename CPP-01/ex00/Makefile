# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 16:45:29 by lebarbos          #+#    #+#              #
#    Updated: 2024/08/02 18:11:12 by lebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = zombie

CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98 -fsanitize=address
				
# Diretórios
SRC_DIR = sources
OBJ_DIR = objs
INCLUDE_DIR = includes

SOURCES = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJECTS = $(SOURCES:.cpp=.o)
SRCS = $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJECTS))
HEADERS = Zombie.hpp
HEADERS_FILES = $(addprefix $(INCLUDE_DIR)/, $(HEADERS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS_FILES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re