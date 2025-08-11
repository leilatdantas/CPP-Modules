# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 21:21:48 by lebarbos          #+#    #+#              #
#    Updated: 2025/08/11 21:21:49 by lebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES_DIR = includes
SOURCES_DIR = sources
OBJECTS_DIR = objects

SOURCES = main.cpp RPN.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJECTS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp
	@mkdir -p $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(OBJECTS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

clean:
	rm -rf $(OBJECTS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
