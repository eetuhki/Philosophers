# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:43:59 by eelaine           #+#    #+#              #
#    Updated: 2025/02/27 22:25:33 by eelaine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR = srcs
SRCS = $(addprefix $(SRC_DIR)/, \
		error.c \
		parse.c \
		philo.c)

OBJ_DIR = objs
OBJECTS	= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./incl

RM = rm -rf

GREEN = \033[0;92m
BLUE = \033[0;94m
END_COLOR = \033[0m

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)philo compiled$(END_COLOR)"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(BLUE)Cleaned philo object files$(END_COLOR)"

fclean:
	@$(RM) $(NAME) $(OBJ_DIR)
	@echo "$(BLUE)Fully cleaned philo$(END_COLOR)"

re: fclean all

valgrind:
	valgrind -v --leak-check=full --show-reachable=yes --track-origins=yes ./philo

.PHONY: all clean fclean re valgrind
