CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

# Directorios
SRCS_DIR	= srcs
LIBFT_DIR	= libft
BONUS_DIR   = srcs_bonus
OBJS_DIR	= objs
LIBFT_OBJ_DIR = libft/objs
OBJS_BONUS_DIR = objs_bonus

# Archivos fuente de ft_printf
FT_PRINTF_SRCS	= ft_printf.c print_char.c print_str.c \
			print_int.c print_uint.c print_hex.c \
			print_ptr.c

# Archivos fuente de bonus
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

# Archivos fuente de libft
LIBFT_SRCS_LIST = $(LIBFT_DIR)/ft_isalpha.c $(LIBFT_DIR)/ft_isdigit.c \
                  $(LIBFT_DIR)/ft_isalnum.c $(LIBFT_DIR)/ft_isascii.c \
                  $(LIBFT_DIR)/ft_isprint.c $(LIBFT_DIR)/ft_strlen.c \
                  $(LIBFT_DIR)/ft_memset.c $(LIBFT_DIR)/ft_bzero.c \
                  $(LIBFT_DIR)/ft_memcpy.c $(LIBFT_DIR)/ft_memmove.c \
                  $(LIBFT_DIR)/ft_strlcpy.c $(LIBFT_DIR)/ft_strlcat.c \
                  $(LIBFT_DIR)/ft_toupper.c $(LIBFT_DIR)/ft_tolower.c \
                  $(LIBFT_DIR)/ft_strchr.c $(LIBFT_DIR)/ft_strrchr.c \
                  $(LIBFT_DIR)/ft_strncmp.c $(LIBFT_DIR)/ft_memchr.c \
                  $(LIBFT_DIR)/ft_memcmp.c $(LIBFT_DIR)/ft_strnstr.c \
                  $(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_calloc.c \
                  $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_substr.c \
                  $(LIBFT_DIR)/ft_strjoin.c $(LIBFT_DIR)/ft_strtrim.c \
                  $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_itoa.c \
                  $(LIBFT_DIR)/ft_strmapi.c $(LIBFT_DIR)/ft_striteri.c \
                  $(LIBFT_DIR)/ft_putchar_fd.c $(LIBFT_DIR)/ft_putstr_fd.c \
                  $(LIBFT_DIR)/ft_putendl_fd.c $(LIBFT_DIR)/ft_putnbr_fd.c

# Paths completos
SRCS		= $(addprefix $(SRCS_DIR)/, $(FT_PRINTF_SRCS))
BONUS		= $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS))
LIBFT_SRCS	= $(LIBFT_SRCS_LIST)

# Archivos objeto
OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS	= $(BONUS:$(BONUS_DIR)/%.c=$(OBJS_BONUS_DIR)/%.o)
LIBFT_OBJS	= $(LIBFT_SRCS:$(LIBFT_DIR)/%.c=$(LIBFT_OBJ_DIR)/%.o)

# Nombre de la librería final
NAME		= libftprintf.a

# Reglas
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	$(AR) $(NAME) $(OBJS) $(LIBFT_OBJS)
	@echo "Biblioteca ft_printf compilada: \033[1;32m$(NAME)\033[0m"

bonus: $(BONUS_OBJS) $(LIBFT_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS) $(LIBFT_OBJS)
	@echo "Bonus compilado y añadido a: \033[1;32m$(NAME)\033[0m"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilando: \033[0;33m$<\033[0m"

$(LIBFT_OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c Makefile libft.h
	@mkdir -p $(LIBFT_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilando libft: \033[0;33m$<\033[0m"

$(OBJS_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c Makefile ft_printf.h
	@mkdir -p $(OBJS_BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilando bonus: \033[0;33m$<\033[0m"

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJS_BONUS_DIR)
	@$(RM) -r $(LIBFT_OBJ_DIR)
	@echo "Archivos objeto eliminados."

fclean: clean
	@$(RM) $(NAME)
	@echo "Biblioteca eliminada."

re: fclean all

.PHONY: all clean fclean re bonus
