# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apanikov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 16:28:31 by apanikov          #+#    #+#              #
#    Updated: 2023/02/07 20:54:21 by apanikov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SRC = $(wildcard *.c)
#OBJ = $(patsubst %.c,%.o,$(SRC))

NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c\
	  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
	  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_strmapi.c ft_striteri.c\
	  ft_putchar_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c\
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c
SRCB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ = $(SRC:%.c=%.o)
OBJB = $(SRCB:.c=.o)
AR = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o : %.c # %.c%.o:
	$(CC) $(CFLAGS) -c $< -o $@

# $@ same $(<:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(SRCB)
#	gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJB)

all: $(NAME)

bonus: $(NAME) $(OBJB)
	$(AR) $(NAME) $(OBJB)
clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(bonus)

re: fclean all

.PHONY : all clean fclean re bonus
