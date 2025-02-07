# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 18:26:53 by anachat           #+#    #+#              #
#    Updated: 2025/02/07 20:34:08 by anachat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        =   push_swap
NAME_BONUS  =   checker

CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror

LIBFT_DIR   =   lib/libft
PRINTF_DIR  =   lib/ft_printf
GNL_DIR     =   lib/get_next_line

LIBFT_LIB   =   $(LIBFT_DIR)/libft.a
PRINTF_LIB  =   $(PRINTF_DIR)/libftprintf.a

GNL_SRCS    =   $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

SRCS        =   $(GNL_SRCS) mandatory/init_stack.c mandatory/push_swap.c \
				mandatory/utils.c mandatory/utils2.c mandatory/operations/push.c \
				mandatory/operations/rotate.c mandatory/operations/swap.c \
				mandatory/operations/reverse_rotate.c \
				mandatory/sorting.c mandatory/sort_algo.c
SRCS_BONUS  =   $(GNL_SRCS) bonus/checker_bonus.c bonus/init_stack_bonus.c bonus/utils_bonus.c bonus/operations/push_bonus.c bonus/operations/reverse_rotate_bonus.c bonus/operations/rotate_bonus.c bonus/operations/swap_bonus.c

OBJS        =   $(SRCS:.c=.o)
OBJS_BONUS        =   $(SRCS_BONUS:.c=.o)

all: $(LIBFT_DIR) $(PRINTF_DIR) $(NAME)

bonus: $(LIBFT_DIR) $(PRINTF_DIR) $(NAME_BONUS)

$(LIBFT_DIR):
	@make -C $(LIBFT_DIR)

$(PRINTF_DIR):
	@make -C $(PRINTF_DIR)

mandatory/%.o: mandatory/%.c $(LIBFT_LIB) $(PRINTF_LIB) mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%_bonus.o: bonus/%_bonus.c $(LIBFT_LIB) $(PRINTF_LIB) bonus/checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf -o $(NAME_BONUS)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: $(LIBFT_DIR) $(PRINTF_DIR)