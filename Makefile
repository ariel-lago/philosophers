# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariellago <ariellago@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/02 14:47:04 by alago-ga          #+#    #+#              #
#    Updated: 2026/02/20 20:45:08 by ariellago        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -g -fsanitize=thread

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes

INC_FILES 	= defines.h init.h parse.h philo.h time_ms.h
INCS 		= $(addprefix includes/, $(INC_FILES))

SRC_FILES	= init.c life.c main.c parse_helpers.c time_ms.c
SRCS		= $(addprefix src/, $(SRC_FILES))

OBJS		= $(addprefix obj/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) created successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@echo "Cleaning Objects$(RESET)"
	@rm -fr $(OBJ_DIR)
	@echo "Cleaned successfully!$(RESET)"
fclean: clean
	@echo "Cleaning Executables$(RESET)"
	@rm -f $(NAME)
	@echo "Cleaned successfully!$(RESET)"

re: fclean all

.PHONY: clean all re fclean



