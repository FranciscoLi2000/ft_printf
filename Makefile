CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

SRCS_DIR	= srcs
BONUS_DIR   = srcs_bonus
LIBFT_DIR	= libft
OBJS_DIR	= objs

FT_PRINTF_SRCS	= ft_printf.c print_char.c print_str.c \
		  print_int.c print_uint.c print_hex.c \
		  print_ptr.c

BONUS_SRCS  = ft_printf_bonus.c \
              parse_hash.c \
              parse_minus.c \
              parse_plus.c \
              parse_precision.c \
              parse_space.c \
              parse_width.c \
              parse_zero.c \
              print_char_bonus.c \
              print_hex_bonus.c \
              print_int_bonus.c \
              print_ptr_bonus.c \
              print_str_bonus.c \
              print_uint_bonus.c

LIBFT_SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		  ft_isascii.c ft_isprint.c ft_strlen.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c \
		  ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		  ft_toupper.c ft_tolower.c ft_strchr.c \
		  ft_strrchr.c ft_strncmp.c ft_memchr.c \
		  ft_memcmp.c ft_strnstr.c ft_atoi.c \
		  ft_calloc.c ft_strdup.c ft_substr.c \
		  ft_strjoin.c ft_strtrim.c ft_split.c \
		  ft_itoa.c ft_strmapi.c ft_striteri.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		  ft_putnbr_fd.c

# Paths completos
# Paths completos
SRCS        = $(addprefix $(SRCS_DIR)/, $(FT_PRINTF_SRCS)) \
              $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS))

BONUS_OBJS  = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:%.c=$(OBJS_DIR)/%.o))

OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

NAME		= libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	echo "Librería compilada: \033[1;32m$(NAME)\033[0m"

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
	echo "Bonus compilado y añadido a: \033[1;32m$(NAME)\033[0m"

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	echo "Compilando: \033[0;33m$<\033[0m"

clean:
	$(RM) -r $(OBJS_DIR)
	echo "Objetos eliminados"

fclean: clean
	$(RM) $(NAME)
	echo "Librería eliminada"

re: fclean all

.PHONY: all clean fclean re bonus
