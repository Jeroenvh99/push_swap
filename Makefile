NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
OVERLAPPING_OBJS = ${OVERLAPPING_SRCS:.c=.o}
SRCS = push_swap.c\
	sort_three.c\
	get_cheapest_ab.c\
	get_cheapest_ba.c\
	sort_list.c\
	sort_list_2.c\
	optimise_instr.c
BONUS_SRCS = checker.c
OVERLAPPING_SRCS = rules.c\
	input_utils.c\
	list_utils.c

all: $(NAME)

$(NAME): $(OBJS) $(OVERLAPPING_OBJS)
	$(MAKE) -j -C ./libft add_bonus
	cc $(OBJS) $(OVERLAPPING_OBJS) $(COMPILEFLAGS) ./libft/libft.a -o $(NAME)

checker: $(BONUS_OBJS) $(OVERLAPPING_OBJS)
	$(MAKE) -j -C ./libft add_bonus
	cc $(BONUS_OBJS) $(OVERLAPPING_OBJS) $(COMPILEFLAGS) ./libft/libft.a -o checker

clean:
	$(MAKE) -j -C ./libft fclean
	rm -f $(OBJS) $(BONUS_OBJS) $(OVERLAPPING_OBJS)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

.PHONY: clean fclean all bonus re

test:
	cc 