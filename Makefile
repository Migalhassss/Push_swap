# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 12:17:02 by tmiguel-          #+#    #+#              #
#    Updated: 2023/02/27 12:17:02 by tmiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_BONUS	= 	checker

FILES		=	check_numbers.c\
				lst_functions.c\
				index.c\
				./Simple_sort/easy_sort.c\
				./Simple_sort/easy_sort_utils.c\
				./Operations/swap.c\
				./Operations/push.c\
				./Operations/reverse.c\
				./Operations/rotate.c\
				sort_100.c\
				sort_100_utils.c\
				sort_500.c\
				sort_500_utils.c\
				push_swap.c\

BONUS_FILES	=	./bonus/checker.c\
				./bonus/checker_utils.c\
				./bonus/checker_utils2.c\
				./bonus/op_bonus/swap_bonus.c\
				./bonus/op_bonus/push_bonus.c\
				./bonus/op_bonus/reverse_bonus.c\
				./bonus/op_bonus/rotate_bonus.c\
				./bonus/gnl/get_next_line.c\
				./bonus/gnl/get_next_line_utils.c\

OBJS		=	$(FILES:.c=.o)
OBJS_BONUS	=	$(BONUS_FILES:.c=.o)

RM	= rm -f

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror 

PRINT_PATH	= ./ft_printf --no-print-directory
PRINT_NAME	= ./ft_printf/libftprintf.a

LIBFT_PATH	= ./libft --no-print-directory
LIBFT_NAME	= ./libft/libft.a

GREEN	= \033[38;5;76m
RED		= \033[38;5;160m
YELLOW	= \033[38;5;226m
INDI	= \033[38;5;99m
RESET	= \033[00m

all: $(PRINT_NAME) $(LIBFT_NAME) $(NAME)

$(PRINT_NAME):
	@echo "$(YELLOW)Compiling everything together...$(INDI)"
	@make -C $(PRINT_PATH)

$(LIBFT_NAME):
	@make -C $(LIBFT_PATH)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_NAME) $(PRINT_NAME)
			@echo "$(YELLOW)Push_swap is ready to run!$(RESET)"

checker:	$(OBJS_BONUS)
			$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT_NAME) $(PRINT_NAME)
			@echo "$(YELLOW)Checker is ready to run!$(RESET)"

clean:
		@echo "$(YELLOW)Cleaning...$(RED)"
		@make fclean -C $(PRINT_PATH)
		@make fclean -C $(LIBFT_PATH)
		$(RM) $(OBJS)
		$(RM) $(OBJS_BONUS)

fclean:		clean
		$(RM) $(NAME)
		$(RM) $(NAME_BONUS)

re:		fclean all

bonus: fclean all checker