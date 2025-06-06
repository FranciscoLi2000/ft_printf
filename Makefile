# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 09:52:32 by yufli             #+#    #+#              #
#    Updated: 2025/06/06 22:34:09 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -rf

LIBFT_DIR	= libft
GNL_DIR		= get_next_line
PRINTF_DIR	= ft_printf
INCLUDES_DIR	= includes

INCLUDES	= -I$(INCLUDES_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR) -I$(LIBFT_DIR)

LIBFT_SRCS	= $(LIBFT_DIR)/ft_strlen.c \
		$(LIBFT_DIR)/ft_itoa.c \
		$(LIBFT_DIR)/ft_strchr.c \
		$(LIBFT_DIR)/ft_strdup.c \
		$(LIBFT_DIR)/ft_substr.c \
		$(LIBFT_DIR)/ft_strjoin.c \
		$(LIBFT_DIR)/ft_strtrim.c \
		$(LIBFT_DIR)/ft_split.c \
		$(LIBFT_DIR)/ft_strmapi.c \
		$(LIBFT_DIR)/ft_striteri.c \
		$(LIBFT_DIR)/ft_putchar_fd.c \
		$(LIBFT_DIR)/ft_putstr_fd.c \
		$(LIBFT_DIR)/ft_putendl_fd.c \
		$(LIBFT_DIR)/ft_putnbr_fd.c \
		$(LIBFT_DIR)/ft_memset.c \
		$(LIBFT_DIR)/ft_bzero.c \
		$(LIBFT_DIR)/ft_memcpy.c \
		$(LIBFT_DIR)/ft_memmove.c \
		$(LIBFT_DIR)/ft_memchr.c \
		$(LIBFT_DIR)/ft_memcmp.c \
		$(LIBFT_DIR)/ft_calloc.c \
		$(LIBFT_DIR)/ft_strncmp.c \
		$(LIBFT_DIR)/ft_strlcpy.c \
		$(LIBFT_DIR)/ft_strlcat.c \
		$(LIBFT_DIR)/ft_strnstr.c \
		$(LIBFT_DIR)/ft_atoi.c \
		$(LIBFT_DIR)/ft_isalpha.c \
		$(LIBFT_DIR)/ft_isdigit.c \
		$(LIBFT_DIR)/ft_isalnum.c \
		$(LIBFT_DIR)/ft_isascii.c \
		$(LIBFT_DIR)/ft_isprint.c \
		$(LIBFT_DIR)/ft_toupper.c \
		$(LIBFT_DIR)/ft_tolower.c \
		$(LIBFT_DIR)/ft_strrchr.c \
		$(LIBFT_DIR)/ft_atoi_base.c \
		$(LIBFT_DIR)/ft_strcmp.c \
		$(LIBFT_DIR)/ft_strcpy.c \
		$(LIBFT_DIR)/ft_strcat.c \
		$(LIBFT_DIR)/ft_strncat.c \
		$(LIBFT_DIR)/ft_strncpy.c \
		$(LIBFT_DIR)/ft_strstr.c \
		$(LIBFT_DIR)/ft_strpbrk.c \
		$(LIBFT_DIR)/ft_strcspn.c \
		$(LIBFT_DIR)/ft_strspn.c \
		$(LIBFT_DIR)/ft_strrev.c \
		$(LIBFT_DIR)/ft_range.c \
		$(LIBFT_DIR)/ft_rrange.c \
		$(LIBFT_DIR)/ft_swap.c \
		$(LIBFT_DIR)/ft_is_prime.c \
		$(LIBFT_DIR)/ft_isspace.c \
		$(LIBFT_DIR)/is_power_of_2.c \
		$(LIBFT_DIR)/lcm.c \
		$(LIBFT_DIR)/max.c \
		$(LIBFT_DIR)/print_bits.c \
		$(LIBFT_DIR)/reverse_bits.c \
		$(LIBFT_DIR)/sort_int_tab.c \
		$(LIBFT_DIR)/swap_bits.c

GNL_SRCS	= $(GNL_DIR)/get_next_line.c

PRINTF_SRCS	= $(PRINTF_DIR)/ft_printf.c \
		$(PRINTF_DIR)/ft_formats.c \
		$(PRINTF_DIR)/ft_utils.c

# Convert all source file paths to their corresponding object file paths
# This transformation happens automatically - Make replaces .c with .o
PRINTF_OBJS	= $(PRINTF_SRCS:.c=.o)
GNL_OBJS	= $(GNL_SRCS:.c=.o)
LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)

# Combine all object files - this represents your complete library
ALL_OBJS	= $(PRINTF_OBJS) $(GNL_OBJS) $(LIBFT_OBJS)

# Color codes for beautiful output - makes the build process more engaging
GREEN		= \033[0;32m
RED		= \033[0;31m
BLUE		= \033[0;34m
YELLOW		= \033[0;33m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
RESET		= \033[0m

# Default target - builds your complete unified library
all: $(NAME)

# Create the unified library from all object files
# This is where all your hard work comes together into one powerful library
$(NAME): $(ALL_OBJS)
	@echo "$(CYAN)===========================================$(RESET)"
	@echo "$(MAGENTA)  Building Library: $(NAME)$(RESET)"
	@echo "$(CYAN)===========================================$(RESET)"
	@echo "$(BLUE)Combining $(words $(ALL_OBJS)) object files into library...$(RESET)"
	@$(AR) $(NAME) $(ALL_OBJS)
	@echo ""
	@echo "$(GREEN)✓ SUCCESS! $(NAME) created successfully!$(RESET)"
	@echo "$(YELLOW)Library Statistics:$(RESET)"
	@echo "ft_printf functions: $(words $(PRINTF_OBJS))"
	@echo "get_next_line functions: $(words $(GNL_OBJS))"
	@echo "libft functions: $(words $(LIBFT_OBJS))"
	@echo "Total functions: $(words $(ALL_OBJS))"
	@echo "$(CYAN)===========================================$(RESET)"

# Pattern rule for compiling C files to object files
# This single rule handles ALL your source files regardless of which directory they're in
%.o: %.c
	@echo "$(BLUE)Compiling $< → $@$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files but preserve the library
# Useful when you want to clean up intermediate files but keep your compiled library
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(ALL_OBJS)
	@echo "$(GREEN)✓ Removed $(words $(ALL_OBJS)) object files$(RESET)"

# Complete cleanup - removes everything including the library
# Forces a complete rebuild from scratch next time
fclean: clean
	@echo "$(RED)Removing library $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ Complete cleanup finished$(RESET)"

# Rebuild everything from scratch - equivalent to fclean + all
re: fclean all

# Declare phony targets (targets that don't create files with their names)
.PHONY: all clean fclean re
