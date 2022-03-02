SRCS =	./srcs/main.c \
		./srcs/utils.c \
		./srcs/check_arg.c \
		./srcs/stack_fct.c \
		./srcs/error.c \
		./srcs/push_swap.c \
		./srcs/cmd_fct/swap_cmd.c \
		./srcs/cmd_fct/push_cmd.c \
		./srcs/cmd_fct/rotate_cmd.c \
		./srcs/cmd_fct/reverse_cmd.c \
		./srcs/algo/easy_algo.c \
		./print_stack.c \


OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

INC		= ./include/

CC		= gcc -Wall -Werror -Wextra -g

RM		= rm -f

all:		${NAME}

.c.o:
		${CC} -I${INC} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${CC} ${OBJS} -I${INC} -o${NAME}

clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all