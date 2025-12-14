# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 11:14:14 by thantoni          #+#    #+#              #
#    Updated: 2025/12/14 15:51:13 by thantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
MLX_DIR = libmlx

LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX = $(MLX_DIR)/libmlx.a

SRCS =  main.c \

INCLUDES = -I. -I$(LIBFT_DIR) -I$(MLX_DIR)
MLX_LIBS = -L$(MLX_DIR) -lmlx -framework Cocoa -framework OpenGL
LIBS = $(LIBFT) $(MLX_LIBS)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(LIBMLX)