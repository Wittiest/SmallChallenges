NAME = tictactoe

CFLAGS += -I ./includes

SRC = ./srcs/class_utilities.cpp ./srcs/tictactoe.cpp

.PHONY = all clean fclean clean re

all: $(NAME)

$(NAME):
	@g++ $(SRC) $(CFLAGS) -o $(NAME)
	@echo "\033[32mCompiled Executable\033[0m"

fclean:
	@rm -rf $(NAME)
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
