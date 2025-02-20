NAME	= libftprintf.a
SRCS	= ft_printf.c ft_printf_utils.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $@ $^

BONUS_SRCS	= ft_printf_bonus.c ft_printf_utils_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re