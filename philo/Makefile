NAME = philo

SRC_DIR = srcs
SRCS = $(addprefix $(SRC_DIR)/, \
		_philo.c \
		clean.c \
		eat.c \
		error.c \
		init.c \
		lock_.c \
		lock_un.c \
		monitor.c \
		parse.c \
		threads.c \
		utils.c)

OBJ_DIR = objs
OBJECTS	= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCL = -I./incl

RM = rm -rf

GREEN = \033[0;92m
BLUE = \033[0;94m
END_COLOR = \033[0m

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)Philo compiled$(END_COLOR)"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(BLUE)Cleaned philo object files$(END_COLOR)"

fclean:
	@$(RM) $(NAME) $(OBJ_DIR)
	@echo "$(BLUE)Fully cleaned philo$(END_COLOR)"

re: fclean all

.PHONY: all clean fclean re
