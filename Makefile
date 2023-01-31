# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 11:37:30 by micarrel          #+#    #+#              #
#    Updated: 2023/01/20 11:37:30 by micarrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

FILES	=	check_numbers.c\
			lst_functions.c\
			index.c\
			./Simple_sort/easy_sort.c\
			./Simple_sort/easy_sort_utils.c\
			./Operations/swap.c\
			./Operations/push.c\
			./Operations/reverse.c\
			./Operations/rotate.c\
			sort2.c\
			push_swap.c\

OBJS	=	$(FILES:.c=.o)

RM	= rm -f

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

PRINT_PATH	= ./ft_printf --no-print-directory
PRINT_NAME	= ./ft_printf/libftprintf.a

LIBFT_PATH	= ./libft --no-print-directory
LIBFT_NAME	= ./libft/libft.a

GREEN	= \033[38;5;76m
RED		= \033[38;5;160m
YELLOW	= \033[38;5;226m
INDI	= \033[38;5;99m
RESET	= \033[00m

all:$(PRINT_NAME) $(LIBFT_NAME)	$(NAME)

$(PRINT_NAME):
	@echo "$(YELLOW)Compiling everything together...$(INDI)"
	@make -C $(PRINT_PATH)

$(LIBFT_NAME):
	@make -C $(LIBFT_PATH)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_NAME) $(PRINT_NAME)
			@echo "$(YELLOW)Push_swap is ready to run!$(RESET)"

clean:
		@echo "$(YELLOW)Cleaning...$(RED)"
		@make fclean -C $(PRINT_PATH)
		@make fclean -C $(LIBFT_PATH)
		$(RM) $(OBJS)

fclean:		clean
		@make fclean -C $(PRINT_PATH)
		@make fclean -C $(LIBFT_PATH)
		$(RM) $(NAME)

re:		fclean all