# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 10:25:59 by lebarbos          #+#    #+#              #
#    Updated: 2024/07/23 10:58:24 by lebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++

CFLAGS = -Werror -Wextra -Wall -std=c++98

OBJ_DIR = objs

HEADERS = PhoneBook.hpp Contact.hpp

SRC_FILES = PhoneBook.cpp Contact.cpp 

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(OBJ_DIR) $(HEADERS)
	$(CC) $(CFLAGS) -c $@ -o $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 