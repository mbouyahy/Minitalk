SRC_CLIENT = client.c support.c

SRC_SERVER = server.c support.c

SRC_CLIENT_BONUS = support.c client_bonus.c

SRC_SERVER_BONUS = support.c server_bonus.c utiles.c

OBJS_CLIENT = ${SRC_CLIENT:.c=.o}

OBJS_SERVER = ${SRC_SERVER:.c=.o}

OBJS_CLIENT_BONUS = ${SRC_CLIENT_BONUS:.c=.o}

OBJS_SERVER_BONUS = ${SRC_SERVER_BONUS:.c=.o}

NAME = server client

RM = rm -f

SERVER_OUT = server

CLIENT_OUT = client

SERVER_BONUS_OUT = server_bonus

CLIENT_BONUS_OUT = client_bonus

CC  = cc

FLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS_SERVER} ${OBJS_CLIENT}
		${CC} ${OBJS_CLIENT} ${FLAGS} -o ${CLIENT_OUT}
		${CC} ${OBJS_SERVER} ${FLAGS} -o ${SERVER_OUT}

clean:
		${RM} ${OBJS_CLIENT} ${OBJS_SERVER} ${OBJS_CLIENT_BONUS} ${OBJS_SERVER_BONUS}

fclean: clean
		${RM} ${SERVER_OUT} ${CLIENT_OUT} ${CLIENT_BONUS_OUT} ${SERVER_BONUS_OUT} 

bonus: ${CLIENT_BONUS_OUT} ${SERVER_BONUS_OUT} 

${CLIENT_BONUS_OUT}: ${OBJS_CLIENT_BONUS}
				${CC} ${FLAGS} $^ -o ${CLIENT_BONUS_OUT}

${SERVER_BONUS_OUT}: ${OBJS_SERVER_BONUS}
				${CC} ${FLAGS} $^ -o ${SERVER_BONUS_OUT}

re: all

.PHONY: all clean fclean bonus re