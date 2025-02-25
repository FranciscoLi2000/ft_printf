CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

# Directories
SRCS_DIR	= srcs
LIBFT_DIR	= libft
BONUS_DIR   = srcs_bonus
OBJS_DIR	= objs
OBJS_BONUS_DIR = objs_bonus

# Source files
FT_PRINTF_SRCS	= ft_printf.c print_char.c print_str.c \
			print_int.c print_uint.c print_hex.c \
			print_ptr.c

LIBFT_SRCS      = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
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

BONUS_SRCS  = ft_printf_bonus.c \
               parse_flag_hash.c \
               parse_flag_minus.c \
               parse_flag_plus.c \
               parse_flag_precision.c \
               parse_flag_space.c \
               parse_flag_width.c \
               parse_flag_zero.c \
               print_char_bonus.c \
               print_hex_bonus.c \
               print_int_bonus.c \
               print_ptr_bonus.c \
               print_str_bonus.c \
               print_uint_bonus.c

# Full paths
SRCS		= $(addprefix $(SRCS_DIR)/, $(FT_PRINTF_SRCS)) \
			$(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS))
BONUS		= $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS))

# Objects
OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS	= $(BONUS:$(BONUS_DIR)/%.c=$(OBJS_BONUS_DIR)/%.o)

# Main library name
NAME		= libftprintf.a

# Rules
all: $(NAME)

# First compile libft, then our ft_printf
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "Library compiled: \033[1;32m$(NAME)\033[0m"

# Bonus rule - compile libft, then bonus objects
bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
	@echo "Bonus compiled and added to: \033[1;32m$(NAME)\033[0m"

# Rule to create object files for mandatory part
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: \033[0;33m$<\033[0m"

# Rule to create object files for bonus part
$(OBJS_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJS_BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling bonus: \033[0;33m$<\033[0m"

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJS_BONUS_DIR)
	@echo "Objects removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "Library removed"

re: fclean all

.PHONY: all clean fclean re bonus