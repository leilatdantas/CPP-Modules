# CPP Module 09 Makefile

.PHONY: all ex00 ex01 ex02 clean fclean re

all: ex00 ex01 ex02

ex00:
	@echo "Building Bitcoin Exchange (ex00)..."
	@$(MAKE) -C ex00

ex01:
	@echo "Building RPN Calculator (ex01)..."
	@$(MAKE) -C ex01

ex02:
	@echo "Building PmergeMe Ford-Johnson Sort (ex02)..."
	@$(MAKE) -C ex02

clean:
	@echo "Cleaning object files..."
	@$(MAKE) -C ex00 clean
	@$(MAKE) -C ex01 clean
	@$(MAKE) -C ex02 clean

fclean:
	@echo "Full clean..."
	@$(MAKE) -C ex00 fclean
	@$(MAKE) -C ex01 fclean
	@$(MAKE) -C ex02 fclean

re: fclean all
