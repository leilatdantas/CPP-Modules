NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES_DIR = includes
SOURCES_DIR = sources
OBJECTS_DIR = objects

SOURCES = main.cpp
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
