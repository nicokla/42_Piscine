
SRCS	= main.c fonctions.c ft_atoi.c ft_putnbr.c
INC_DIR	= .

OBJS	= ${SRCS:.c=.o}

NAME	= do-op

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I$(INC_DIR)

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
