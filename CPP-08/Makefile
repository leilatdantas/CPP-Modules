SUBDIRS = ex00 ex01 ex02

all:
	@for dir in $(SUBDIRS); do \
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir; \
		echo ""; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		echo "Cleaning $$dir..."; \
		$(MAKE) -C $$dir clean; \
	done

fclean:
	@for dir in $(SUBDIRS); do \
		echo "Full cleaning $$dir..."; \
		$(MAKE) -C $$dir fclean; \
	done

re:
	@for dir in $(SUBDIRS); do \
		echo "Rebuilding $$dir..."; \
		$(MAKE) -C $$dir re; \
		echo ""; \
	done

test:
	@echo "Testing ex00..."; \
	$(MAKE) -C ex00 && cd ex00 && ./easyfind 2>/dev/null | head -15 && cd ..; \
	echo ""; \
	echo "Testing ex01..."; \
	$(MAKE) -C ex01 && cd ex01 && ./span 2>/dev/null | head -15 && cd ..; \
	echo ""; \
	echo "Testing ex02..."; \
	$(MAKE) -C ex02 && cd ex02 && ./mutantstack 2>/dev/null | head -15 && cd ..; \
	echo "";

.PHONY: all clean fclean re test
