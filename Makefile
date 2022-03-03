SRCS	= main.c file.c map.c solve.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

GCC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

ICLD = file.h map.h solve.h

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${GCC} -o ${NAME} ${OBJS} -I${ICLD}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:        clean
        ${RM} ${NAME}

re:        fclean all

.PHONY: all clean fclean re
