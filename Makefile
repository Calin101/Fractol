# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/12/14 02:04:28 by lubrun       #+#   ##    ##    #+#        #
#    Updated: 2019/04/08 15:23:20 by calin       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fractol

SRCS = 	srcs/algo.c\
		srcs/color.c\
		srcs/ft_utils.c\
		srcs/inputs.c\
		srcs/inputs2.c\
		srcs/main.c\
		srcs/parsing.c\
		srcs/sierpinski.c\

OBJ = $(SRCS:%.c=%.o)

INC = includes/fractol.h

CFLAGS = -Wall -Werror -Wextra -O3

LIBFT = libft/libft.a

LIBMLX = minilibx_macos/libmlx.a 

OPENGL = -framework OpenGL -framework AppKit

all: $(NAME) 

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	gcc $(CFLAGS) $^ $(OPENGL) -o $@

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $< -o $@
	
$(LIBFT):
	make -C libft/

$(LIBMLX):
	make -C minilibx_macos/

clean:
	make clean -C libft/
	make clean -C minilibx_macos/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re:	fclean all
	make re -C minilibx_macos/

norme:
	@norminette $(SRCS)
	@norminette $(INC)
	@make norme -C libft

.PHONY: all clean fclean re norme
