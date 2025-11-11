# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsouza <jsouza@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 17:16:47 by jsouza            #+#    #+#              #
#    Updated: 2025/11/11 14:26:17 by jsouza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/libft.a

CC = cc -Wall -Wextra -Werror -I .

AR = ar rcs

SRC = ft_printf_utils.c ft_printf.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIB_OBJ = libft/obj/ft_atoi.o \
	libft/obj/ft_bzero.o \
	libft/obj/ft_calloc.o \
	libft/obj/ft_isalnum.o \
	libft/obj/ft_isalpha.o \
	libft/obj/ft_isascii.o \
	libft/obj/ft_isdigit.o \
	libft/obj/ft_isprint.o \
	libft/obj/ft_itoa.o \
	libft/obj/ft_lstadd_back_bonus.o \
	libft/obj/ft_lstadd_front_bonus.o \
	libft/obj/ft_lstclear_bonus.o \
	libft/obj/ft_lstdelone_bonus.o \
	libft/obj/ft_lstiter_bonus.o \
	libft/obj/ft_lstlast_bonus.o \
	libft/obj/ft_lstmap_bonus.o \
	libft/obj/ft_lstnew_bonus.o \
	libft/obj/ft_lstsize_bonus.o \
	libft/obj/ft_memchr.o \
	libft/obj/ft_memcmp.o \
	libft/obj/ft_memcpy.o \
	libft/obj/ft_memmove.o \
	libft/obj/ft_memset.o \
	libft/obj/ft_putchar_fd.o \
	libft/obj/ft_putendl_fd.o \
	libft/obj/ft_putnbr_fd.o \
	libft/obj/ft_putstr_fd.o \
	libft/obj/ft_split.o \
	libft/obj/ft_strchr.o \
	libft/obj/ft_strdup.o \
	libft/obj/ft_striteri.o \
	libft/obj/ft_strjoin.o \
	libft/obj/ft_strlcat.o \
	libft/obj/ft_strlcpy.o \
	libft/obj/ft_strlen.o \
	libft/obj/ft_strmapi.o \
	libft/obj/ft_strncmp.o \
	libft/obj/ft_strnstr.o \
	libft/obj/ft_strrchr.o \
	libft/obj/ft_strtrim.o \
	libft/obj/ft_substr.o \
	libft/obj/ft_tolower.o \
	libft/obj/ft_toupper.o

OBJ_DIR = obj

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(AR) $(NAME) $(OBJ) $(LIB_OBJ)

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

test: all $(LIB_OBJ)
	@cc tests/test.c $(NAME) -o test
	@./test
	@rm -f test
	@rm -f libftprintf.a
	@rm -rf libft/obj
	@rm -rf obj

.PHONY: all clean fclean re