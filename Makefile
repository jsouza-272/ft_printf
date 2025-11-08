# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsouza <jsouza@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 17:16:47 by jsouza            #+#    #+#              #
#    Updated: 2025/11/07 16:23:18 by jsouza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/libft.a

CC = cc -Wall -Wextra -Werror -I .

AR = ar rcs

SRC = ft_printf_utils.c ft_printf.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_DIR = obj

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) -c $< -o $@

clean:
	@$(MAKE) clean -C libft
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re