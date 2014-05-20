# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/10 21:28:36 by ael-kadh          #+#    #+#              #
#    Updated: 2013/12/22 03:59:50 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = get_next_line.c main_mlx.c event.c reading.c matrix.c deplacer.c \
		sinus.c perspective.c transformations.c draw.c math.c draw_2.c
HEAD = fdf.h get_next_line.h
OBJ = $(SRC:.c=.o) 
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -I libft/includes -I /usr/include -c $(SRC)
	@gcc $(OBJ) -L libft -lft -L/usr/X11/lib -lmlx -lXext -lX11 -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
