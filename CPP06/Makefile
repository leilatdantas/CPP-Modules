# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 10:54:20 by lebarbos          #+#    #+#              #
#    Updated: 2025/03/03 10:58:17 by lebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = convert

CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98

# Diretórios
SRC_DIR = sources
OBJ_DIR = objs
INCLUDE_DIR = includes

SOURCES = main.cpp $(HEADERS:.hpp=.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
SRCS = $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJECTS))
HEADERS = ScalarConverter.hpp
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