# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 15:47:30 by lebarbos          #+#    #+#              #
#    Updated: 2024/08/29 21:38:01 by lebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = materia

CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98 #-fsanitize=address

# Diretórios
SRC_DIR = sources
OBJ_DIR = objs
INCLUDE_DIR = includes

SOURCES = main.cpp AMateria.cpp MateriaSource.cpp Ice.cpp Cure.cpp Character.cpp
OBJECTS = $(SOURCES:.cpp=.o)
SRCS = $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJECTS))
HEADERS = MateriaSource.hpp IMateriaSource.hpp ICharacter.hpp Ice.hpp Cure.hpp Character.hpp AMateria.hpp 
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