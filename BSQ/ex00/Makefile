SRC_DIR		= source/
SOURCES		= ${SRC_DIR}main.c ${SRC_DIR}file.c ${SRC_DIR}map.c ${SRC_DIR}solve.c

OBJS		= ${SOURCES:.c=.o}

NAME		= bsq

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:				fclean all

.PHONY:		all clean fclean re
