# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecott <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 09:33:30 by alecott           #+#    #+#              #
#    Updated: 2018/04/20 12:19:03 by rkrief           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = libft.a

LIB_PATH = ./libft/

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

NAME = lem-in

CFLAGS = -Wall -Werror -Wextra -g

INC = lem_in.h

SRCS_PATH = ./srcs/

ALL_SRCS = main.c ft_norm.c ft_stock.c ft_names.c ft_error.c ft_verify.c ft_tubestr.c ft_room_number.c ft_check_ant.c \
ft_fill_path.c ft_move_tubes.c ft_feel_free.c ft_rm_last_one.c ft_sort_tubes_and_repeat.c ft_get_room.c ft_find_room_intube.c \
ft_get_last_inpath.c ft_complete_path.c ft_check_ifexist.c

SRCS = $(addprefix $(SRCS_PATH), $(ALL_SRCS))

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@$(MAKE) -C libft
	@gcc $(CFLAGS) $(OBJ) -L libft -lft -o $(NAME)

%.o:$(SRCS_PATH)%.c
	gcc -c $< -o $@ $(CFLAGS)

clean:
	@$(MAKE) -C libft $@
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft $@
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
