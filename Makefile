# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 14:30:37 by bdjoco            #+#    #+#              #
#    Updated: 2025/08/04 17:35:23 by bdjoco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

AR = ar rcs
RM = rm -f

SRC = src/philo.c \
		src/extra.c \
		src/utils.c

OBJ = $(SRC:.c=.o)

MAKE = make -s -C

BOLD = \e[1m
GREEN = \e[32m
PURPLE = \e[35m
RESET = \e[0m

all : $(NAME)

$(NAME) : $(OBJ) $(LIBS)
	@echo "🔱 $(BOLD)$(PURPLE)$(NAME)$(RESET)$(GREEN) est compilé$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	@echo "Compiling : $(PURPLE)$<$(NC)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ)
	@echo "$(GREEN)Nettoyage des $(RESET)$(BOLD)fichiers source de philosophers$(RESET) $(GREEN)terminé$(RESET) 🚮"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(GREEN)Nettoyage de $(RESET)$(BOLD)philo.a$(RESET) $(GREEN)terminé$(RESET) 🚮"

#----------------------------------------------------------------------#

test : all clean
	@echo "🔱 $(PURPLE)On cook$(RESET) 🔱"

#----------------------------------------------------------------------#

re : fclean all

.PHONY: all clean fclean re
