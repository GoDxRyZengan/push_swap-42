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
		./srcs/algo/new_algo.c \
		./srcs/algo/algo_utils.c \
		./srcs/algo/algo_utils_2.c \
		./srcs/algo/algo_utils_3.c \

SRCS_BONUS =	./srcs/bonus/main_bonus.c \
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
				./srcs/algo/new_algo.c \
				./srcs/algo/algo_utils.c \
				./srcs/algo/algo_utils_2.c \
				./srcs/algo/algo_utils_3.c \


OBJS	= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME	= push_swap

NAME_BONUS = push_swap_bonus

INC		= ./include/

CC		= gcc -Wall -Werror -Wextra -g

RM		= rm -f

all:		${NAME}

.c.o:
		${CC} -I${INC} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${CC} ${OBJS} -I${INC} -o${NAME}

bonus:		${NAME_BONUS}

.c.o:
		${CC} -I${INC} -c $< -o ${<:.c=.o}

$(NAME_BONUS):	${OBJS_BONUS}
		${CC} ${OBJS_BONUS} -I${INC} -o${NAME_BONUS}

clean:		
		${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
		${RM} ${NAME} ${NAME_BONUS}

re:		fclean all
