# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 22:04:21 by bbouagou          #+#    #+#              #
#    Updated: 2023/01/06 22:26:42 by bbouagou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = ft_bzero.o ft_calloc.o ft_delete_list.o ft_delete_node.o ft_itoa.o ft_len.o ft_lstadd_back.o\
ft_lstadd_front.o ft_lstlast.o ft_lstnew.o ft_lstsize.o ft_strchr.o ft_strjoin.o ft_strlcpy.o ft_strnstr.o\
get_next_line_utils.o get_next_line.o
DEPS = ../includes/libft.h

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus