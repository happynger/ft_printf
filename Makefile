# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 18:22:37 by otahirov          #+#    #+#              #
#    Updated: 2018/11/30 12:48:18 by otahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

LIBLOC= libft
LIBSRC= $(LIBLOC)/*.c
LIBBIN= *.o
INC= -I $(LIBLOC)/includes

SRC= colors.c ft_printbank.c ft_printf.c ft_prints.c globals.c postprocess.c
BIN= $(SRC:.c=.o)

CC= gcc
FLAGS= -Wall -Wextra -Werror -c

RM= rm -f

all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(LIBSRC) $(INC)
	@$(CC) $(FLAGS) $(SRC) $(INC)
	@ar rc $(NAME) $(BIN) $(LIBBIN)
	@ranlib $(NAME)
	@echo "Lib Generated"

clean :
	@$(RM) $(LIBBIN)
	@$(RM) $(BIN)
	@echo "Deleted All Objects"

fclean : clean
	@$(RM) $(NAME)
	@echo "Deleted the $(NAME)"

re : fclean all

git :
	@git add .
	@git commit -m "Automated Update $(shell date | head -c 19 | tail -c 15 && echo)"
	@git push
	@echo "The update was pushed to the github"