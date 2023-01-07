# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 21:10:43 by bbouagou          #+#    #+#              #
#    Updated: 2023/01/07 00:03:15 by bbouagou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS =  -lmlx -framework OpenGL -framework AppKit

OBJ = ft_map_error_handeling.o ft_map_parsing_utils.o ft_map_parsing.o\
ft_path_checking_utils.o ft_path_checking.o ft_animate.o ft_animation_utils.o ft_draw_map.o\
ft_drawing_utils.o ft_player_mouvement.o ft_enemies_logic.o ft_inject_enemies.o ft_move_enemies.o

OBJBONUS = ft_map_error_handeling.o ft_map_parsing_utils.o ft_map_parsing.o\
ft_path_checking_utils.o ft_path_checking.o ft_animate_bonus.o ft_animation_utils_bonus.o ft_draw_map_bonus.o\
ft_drawing_utils_bonus.o ft_player_mouvement_bonus.o ft_enemies_logic.o ft_inject_enemies.o ft_move_enemies.o

SRC = map_checking/ft_map_error_handeling.c map_checking/ft_map_parsing_utils.c map_checking/ft_map_parsing.c\
map_checking/ft_path_checking_utils.c map_checking/ft_path_checking.c map_rendering/ft_animate.c\
map_rendering/ft_animation_utils.c map_rendering/ft_draw_map.c map_rendering/ft_drawing_utils.c\
map_rendering/ft_player_mouvement.c enemies_handling/ft_enemies_logic.c enemies_handling/ft_inject_enemies.c\
enemies_handling/ft_move_enemies.c enemies_handling/ft_enemies_logic.c enemies_handling/ft_inject_enemies.c\
enemies_handling/ft_move_enemies.c

BONUS = map_checking/ft_map_error_handeling.c map_checking/ft_map_parsing_utils.c map_checking/ft_map_parsing.c\
map_checking/ft_path_checking_utils.c map_checking/ft_path_checking.c map_rendering_bonus/ft_animate_bonus.c\
map_rendering_bonus/ft_animation_utils_bonus.c map_rendering_bonus/ft_draw_map_bonus.c\
map_rendering_bonus/ft_drawing_utils_bonus.c map_rendering_bonus/ft_player_mouvement_bonus.c\
enemies_handling/ft_enemies_logic.c enemies_handling/ft_inject_enemies.c enemies_handling/ft_move_enemies.c

all : $(NAME)

compile :
	$(MAKE) re -C libft
	$(CC) $(SRC) -c

compile_bonus :
	$(MAKE) re -C libft
	$(CC) $(BONUS) -c

$(NAME) : compile
	$(CC) main.c $(CFLAGS) $(MLXFLAGS) $(OBJ) libft/libft.a -o $(NAME)

bonus : compile_bonus
	$(CC) main.c $(CFLAGS) $(MLXFLAGS) $(OBJBONUS) libft/libft.a -o $(NAME)

clean :
	$(MAKE) clean -C libft 
	rm -rf *.o

fclean : clean
	$(MAKE) fclean -C libft 
	rm -rf so_long