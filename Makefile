NAME=libasm.a
COMPILER=nasm
# Linux flags
FLAGS=-f elf64
# Mac flags
ifeq ($(shell uname), Darwin)
   FLAGS = -f macho64
endif
SRC_PATH = src/
OBJ_PATH = obj/

SRC_NAME = ft_strlen.s \
					 ft_strcpy.s \
					 ft_strcmp.s \
					 ft_write.s \
					 ft_read.s \
					 ft_strdup.s

OBJ_NAME = $(SRC_NAME:.s=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))


$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.s
	@mkdir -p $(@D)
	$(COMPILER) $(FLAGS) $< -o $@

all: $(NAME)

test: re
	make test -s -C test/

re: fclean all

clean:
	rm -rf obj
	make clean -s -C test/

fclean: clean
	rm -rf $(NAME)
	make fclean -s -C test/

.PHONY: all clean fclean re
