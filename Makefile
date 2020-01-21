# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/12 14:59:42 by plogan            #+#    #+#              #
#    Updated: 2017/06/28 18:12:11 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_NAME = 	lem-in.c check_comment.c check_first_line.c check_room_tube.c \
		  	ft_room_list_push.c ft_singleton.c ft_tube_list_push.c \
			display_on.c create_path_tree.c create_paths.c save_path.c \
			display_paths.c add_path.c pathfinder.c remove_last_path.c \
			remove_last_paths.c free_paths.c get_nb_turns.c

OFILES = $(SRC_NAME:.c=.o)

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

all: makelibs $(NAME)

makelibs:
	@make -C Libft

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) Libft/libft.a \
		Libft/my_printf/libftprintf.a -o $(NAME)
	@echo "Compilation checker:\033[92m OK\033[0m"

%.o: $(SRC_PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< -I includes

clean:
	@make -C Libft clean
	@rm -rf $(OFILES)
	@echo "Deleting:\n\033[33m $(OFILES)\033[0m"

fclean: clean
	@make -C Libft fclean
	@rm -rf $(NAME)
	@echo "Deleting:\033[33m $(NAME)\033[0m"

re : fclean all

.PHONY: all clean fclean re
