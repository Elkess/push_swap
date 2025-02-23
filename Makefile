NAME = push_swap
CC = cc
CFLAGS = 

SRC = push_swap.c ft_atoi.c push_swap_utils.c ft_strcmp.c ft_strjoin.c ft_split.c ft_strdup.c \
      ft_strlen.c ft_substr.c initiate_stack.c is_it_sorted.c moves.c global_moves.c stack_len.c\
      sort_three_and_less.c sorting.c sorting_utils.c write_moves1.c write_moves2.c  garbage_collective.c
OBJS = $(SRC:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean
