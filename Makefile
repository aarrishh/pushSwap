NAME = push_swap
INC_DIR = includes
SRC_DIR = src

SRC =  $(SRC_DIR)/butterfly.c  $(SRC_DIR)/butterfly1.c  $(SRC_DIR)/functions.c \
		$(SRC_DIR)/functions1.c  $(SRC_DIR)/main.c  $(SRC_DIR)/operations.c \
		$(SRC_DIR)/operations1.c  $(SRC_DIR)/sorting.c  $(SRC_DIR)/split.c \
		$(SRC_DIR)/validation.c


OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)  -fsanitize=address -g3

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re