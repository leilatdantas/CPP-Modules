# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 11:20:27 by lebarbos          #+#    #+#              #
#    Updated: 2024/07/30 11:20:30 by lebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

CC = c++

CFLAGS = -Werror -Wextra -Wall -std=c++98

OBJ_DIR = objs

HEADERS = Account.hpp

SRC_FILES = Account.cpp tests.cpp

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	
$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re