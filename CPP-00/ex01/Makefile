# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 10:25:59 by lebarbos          #+#    #+#              #
#    Updated: 2024/07/25 17:02:06 by lebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98

OBJ_DIR = objs

HEADERS = PhoneBook.hpp Contact.hpp Utilities.hpp

SRC_FILES = PhoneBook.cpp Contact.cpp main.cpp Utilities.cpp
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:.cpp=.o)))

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
