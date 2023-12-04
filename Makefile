SRCS			:=	check_entry.c \
					main.c \
					sort.c \
					sort_op.c \
					sort_op2.c \
					stack_op_a.c \
					stack_op_ab.c \
					stack_op_b.c \
					stack.c \
					split.c \
					sort_exceptions.c \
					quicksort.c

SRCS2			:=	check_entry.c \
					bonus/checker_bonus.c \
					bonus/sort_functions_bonus.c \
					bonus/stack_a_bonus.c \
					bonus/stack_ab_bonus.c \
					bonus/stack_b_bonus.c \
					bonus/stack_bonus.c \
					bonus/get_next_line_bonus.c \
					bonus/get_next_line_utils_bonus.c \
					bonus/read_entry_bonus.c \
					split.c
					

OBJS			:= $(SRCS:.c=.o)

OBJS2			:= $(SRCS2:.c=.o)

CC				:= gcc
RM				:= rm -f
CFLAGS			:= -Wall -Wextra -Werror -I.

NAME			:= push_swap

BONUS			:= checker

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus:			$(BONUS)

$(BONUS):		$(OBJS2)
				$(CC) $(CFLAGS) -o $(BONUS) $(OBJS2)

clean:
				$(RM) $(OBJS) $(OBJS2)

fclean:			clean
				$(RM) $(NAME) $(BONUS)

re:				fclean $(NAME)
	
.PHONY:			all clean fclean re bonus