# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 17:54:24 by dvargas           #+#    #+#              #
#    Updated: 2022/09/06 09:41:12 by dvargas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	push.c 
OBJS		= ${SRCS:%.c=%.o}
NAME		= push_swap
LIB			= libft/libft.a
CC			= cc
CCFLAGS		= -Wall -Wextra -Werror -I libft/
LIBFT_PATH  = libft/

all:		${NAME}

$(NAME):	${OBJS}
			@ echo 'Creating the monster'
			make all -C $(LIBFT_PATH)
			${CC} ${CCFLAGS} ${OBJS} ${LIB} -o ${NAME}
			@ echo 'ITS ALIVE!!!!!!!!!'
			@ echo ' '

%.o: %.c
			${CC} ${CCFLAGS} -c $< -o $@
			@ echo ' '

clean:
			@ echo 'clean rule'
			rm -f ${OBJS} bonus.o
			make clean -C $(LIBFT_PATH)
			@ echo ' '

fclean:		clean
			@ echo 'Removing pipex and pipex bonus'
			rm -f ${NAMEBONUS}
			rm -f ${NAME}
			make fclean -C $(LIBFT_PATH)
			@ echo ' '

re:			fclean all
			@ echo 're rule. . . .$<'
			@ echo ' '

.PHONY:		all clean fclean re
