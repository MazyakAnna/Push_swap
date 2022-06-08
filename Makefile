NAME = push_swap

BONUS_NAME = checker

SRCS = 	common_utils.c \
		doubly_linked_lists.c \
		sort_0radix.c \
		sort_small_stack.c \
		sort_stack.c \
		sort_stack_utils.c \
		sort_stack_utils2.c \
		index_stack.c \
		stack_moves.c \
		stack_moves2.c \
		stack_ops.c \
		stack_utils.c \
		inits.c

MAIN = push_swap.c

BONUS_SRCS = get_next_line.c \
		get_next_line_utils.c \
		checker.c \
		checker_utils.c

HDRS 		= push_swap.h

OBJS		= ${SRCS:.c=.o}
MAIN_OBJ	= ${MAIN:.c=.o}
BONUS_OBJS	= ${BONUS_SRCS:.c=.o}

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I /includes/

all:	${NAME}

bonus:	${BONUS_NAME}

${OBJS}: ${HDRS}
${MAIN_OBJ}: ${HDRS}
${BONUS_OBJS}: ${HDRS}

.c.o:	
		${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS} ${MAIN_OBJ}
		${CC} ${CFLAGS} ${OBJS} ${MAIN_OBJ} -o ${NAME}

$(BONUS_NAME): ${OBJS} ${BONUS_OBJS}
		${CC} ${CFLAGS} ${OBJS} ${BONUS_OBJS} -o ${BONUS_NAME}

clean:
		${RM} ${OBJS} ${MAIN_OBJ} ${BONUS_OBJS}

fclean:	clean
		${RM} ${NAME} ${BONUS_NAME}

re:		fclean
	make all

.PHONY : all clean fclean re