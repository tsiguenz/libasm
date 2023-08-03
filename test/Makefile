NAME = libasm-tests
LIBASM = ../libasm.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
# Mac arm flags
ifeq ($(shell uname), Darwin)
   FLAGS += -target x86_64-apple-darwin22.4.0
endif
SRC_PATH = src/
OBJ_PATH = obj/

SRC_NAME = main.c \
					 strlen_tests.c \
					 strcpy_tests.c \
					 strcmp_tests.c \
					 write_tests.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))


$(NAME): $(OBJ)
	@make -s -C ../
	$(CC) $(FLAGS) $(OBJ) $(LIBASM) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

test: $(NAME)
	./$(NAME)

re: fclean all

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean fclean re
