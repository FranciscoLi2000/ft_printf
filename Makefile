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

INCLUDES_DIR	= includes

INCLUDES	= -I$(INCLUDES_DIR)

PRINTF_SRCS	= ft_printf.c ft_formats.c ft_utils.c

# Convert all source file paths to their corresponding object file paths
# This transformation happens automatically - Make replaces .c with .o
PRINTF_OBJS	= $(PRINTF_SRCS:.c=.o)

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
$(NAME): $(PRINTF_OBJS)
	@$(AR) $(NAME) $(PRINTF_OBJS)

# Pattern rule for compiling C files to object files
# This single rule handles ALL your source files regardless of which directory they're in
%.o: %.c
	@echo "$(BLUE)Compiling $< → $@$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files but preserve the library
# Useful when you want to clean up intermediate files but keep your compiled library
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(PRINTF_OBJS)
	@echo "$(GREEN)✓ Removed object files$(RESET)"

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
