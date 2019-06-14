# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 16:04:09 by yinzhang          #+#    #+#              #
#    Updated: 2019/03/04 11:42:35 by yinzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CFLAGS		= -Wall -Werror -Wextra

INCLUDE		= libft.h \

FILES		= ft_atoi.c \
			  ft_bzero.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_itoa.c \
			  ft_lstadd.c \
			  ft_lstdel.c \
			  ft_lstdelone.c \
			  ft_lstnew.c \
			  ft_lstiter.c \
			  ft_lstmap.c \
			  ft_memalloc.c \
			  ft_memccpy.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memdel.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_putchar.c \
			  ft_putchar_fd.c \
			  ft_putendl.c \
			  ft_putendl_fd.c \
			  ft_putnbr.c \
			  ft_putnbr_fd.c \
			  ft_putstr.c \
			  ft_putstr_fd.c \
			  ft_strcat.c \
			  ft_strchr.c \
			  ft_strclr.c \
			  ft_strcmp.c \
			  ft_strcpy.c \
			  ft_strdel.c \
			  ft_strdup.c \
			  ft_strequ.c \
			  ft_striter.c \
			  ft_striteri.c \
			  ft_strjoin.c \
			  ft_strlcat.c \
			  ft_strlen.c \
			  ft_strmap.c \
			  ft_strmapi.c \
			  ft_strncat.c \
			  ft_strncmp.c \
			  ft_strncpy.c \
			  ft_strnequ.c \
			  ft_strnew.c \
			  ft_strnstr.c \
			  ft_strrchr.c \
			  ft_strsplit.c \
			  ft_strstr.c \
			  ft_strsub.c \
			  ft_strtrim.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_wordlen.c \
			  ft_countword.c \
			  ft_strrev.c \
			  ft_islower.c \
			  ft_isupper.c \
			  ft_strndup.c \

OBJ	= $(FILES:.c=.o)

all: $(NAME)

$(NAME): 
	@gcc -c $(CFLAGS) $(FILES) -I$(INCLUDE) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)	   

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
