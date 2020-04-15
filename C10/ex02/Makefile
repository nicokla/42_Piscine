
SRCS	= main.c utils.c ft_atoi.c main2.c
INC_DIR	= .

OBJS	= ${SRCS:.c=.o}

NAME	= ft_tail

CC		= gcc
RM		= rm -f

CFLAGS	= -g -Wall -Wextra -Werror -I$(INC_DIR)

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -g -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
