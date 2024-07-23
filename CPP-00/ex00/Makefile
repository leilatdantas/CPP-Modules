# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 09:37:19 by lebarbos          #+#    #+#              #
#    Updated: 2024/07/23 10:56:43 by lebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++

CFLAGS = -Werror -Wextra -Wall -std=c++98 -fsanitize=address

OBJ_DIR = objs

HEADERS = 

SRC_FILES = Megaphone.cpp

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	
$(OBJ_DIR)/%.o: %.cpp $(OBJ_DIR) $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR): 
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re