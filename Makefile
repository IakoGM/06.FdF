# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 14:13:54 by jakgonza          #+#    #+#              #
#    Updated: 2023/08/30 13:46:54 by jakgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = 	main.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra

LIBFT = libft/libft.a

MLX = mlx/libmlx.a

GNL = gnl/gnl.a

all: $(NAME)

$(LIBFT):
	@make -C ./libft

$(MLX):
	@make -C ./mlx

$(GNL):
	@make -C ./gnl

%.o: %.c
	gcc $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(MLX)
	gcc $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) $(MLX) -lXext -lX11 -o $(NAME)

clean:
	rm -f $(OBJS)
	@echo "Object files removed"
	@make clean -C ./libft
	@make clean -C ./mlx
	@make clean -C ./gnl

fclean:
	rm -f $(NAME)
	@echo "Library removed"
	@make fclean -C ./libft
	@make fclean -C ./gnl

re: fclean all

iako: clean fclean

.PHONY: all clean fclean re iako
