# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 11:14:14 by thantoni          #+#    #+#              #
#    Updated: 2025/12/14 17:52:26 by thantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3

# --- Libft ---
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
LIBFT_INC   = -I$(LIBFT_DIR)

# --- Sources ---
SRCS        = main.c
OBJS        = $(SRCS:.c=.o)

# --- Configuration Linux ---
MLX_DIR_LINUX   = ./libmlx_linux
MLX_FLAGS_LINUX = -L$(MLX_DIR_LINUX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES_LINUX  = -I/usr/include -I$(MLX_DIR_LINUX) -I.

# --- Configuration Metal (macOS) ---
MLX_DIR_METAL   = ./libmlx_metal
MLX_FLAGS_METAL = -L$(MLX_DIR_METAL) -lmlx -framework Cocoa -framework Metal -framework MetalKit
INCLUDES_METAL  = -I$(MLX_DIR_METAL) -I.
COPY_DYLIB      = install_name_tool -change libmlx.dylib @executable_path/$(MLX_DIR_METAL)/libmlx.dylib $(NAME)

# --- Règles ---

# Si on tape juste "make", on affiche l'aide
all:
	@echo "Error: Too few arguments, must specify target plateform"
	@echo "Error: <make> <[metal] or [linux]>"

# Règle Linux
linux: MLX_DIR = $(MLX_DIR_LINUX)
linux: MLX_FLAGS = $(MLX_FLAGS_LINUX)
linux: INCLUDES = $(INCLUDES_LINUX) $(LIBFT_INC)
linux: $(NAME)

# Règle Metal
metal: MLX_DIR = $(MLX_DIR_METAL)
metal: MLX_FLAGS = $(MLX_FLAGS_METAL)
metal: INCLUDES = $(INCLUDES_METAL) $(LIBFT_INC)
metal: CMD_COPY = $(COPY_DYLIB)
metal: $(NAME)

# Compilation des objets
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Linkage
$(NAME): $(OBJS) $(LIBFT)
	@if [ -z "$(MLX_DIR)" ]; then \
		echo "Error: <make> <[metal] or [linux]>"; \
		exit 1; \
	fi
	@make -C $(MLX_DIR)
	$(CC) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@$(CMD_COPY)

$(LIBFT):
	@make -C $(LIBFT_DIR)

# Nettoyage
clean:
	rm -f $(OBJS)
	-@make -s clean -C $(LIBFT_DIR)
	-@if [ -d "$(MLX_DIR_LINUX)" ]; then make -s clean -C $(MLX_DIR_LINUX); fi
	-@if [ -d "$(MLX_DIR_METAL)" ]; then make -s clean -C $(MLX_DIR_METAL); fi

fclean: clean
	rm -f $(NAME)
	rm -f libmlx.dylib
	-@make -s fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re linux metal