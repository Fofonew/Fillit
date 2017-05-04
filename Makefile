# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/22 01:47:30 by doriol            #+#    #+#              #
#    Updated: 2017/04/22 01:50:28 by doriol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ./srcs/ft_strsplit.c\
	./srcs/display_file.c\
	./srcs/main.c\
	./srcs/ft_check_block.c\
	./srcs/ft_print.c\
	./srcs/ft_putstr.c\
	./srcs/ft_cleaner.c\
	./srcs/up_toleft.c\
	./srcs/ft_print.c\
	./srcs/initmap.c\
	./srcs/solve.c\

SRCS2 =	ft_strsplit.o\
	display_file.o\
	main.o\
	ft_check_block.o\
	ft_putstr.o\
	ft_cleaner.o\
	up_toleft.o\
	ft_print.o\
	initmap.o\
	solve.o\

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS2)
	@mkdir obj
	@mv *.o obj/
	@echo "\033[32mFILLIT compiled [ ✔ ]"

clean:
	@rm -rf obj/
	@echo "\033[32mFILLIT cleaned [ ✔ ]"

fclean: clean
	@rm -f $(NAME)

re: fclean all
