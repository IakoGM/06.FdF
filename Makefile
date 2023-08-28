# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 14:13:54 by jakgonza          #+#    #+#              #
#    Updated: 2023/08/28 16:35:00 by jakgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = 	main.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra

LIBFT = libft/libft.a

MLX = mlx/libmlx.a

all: $(NAME)

$(LIBFT):
	@make -C ./libft

$(MLX):
	@make -C ./mlx

%.o: %.c
	gcc $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	gcc $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)
	@echo "Object files removed"
	@make clean -C ./libft
	@make clean -C ./mlx

fclean:
	rm -f $(NAME)
	@echo "Library removed"
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
