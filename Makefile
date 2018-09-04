# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 16:20:34 by oshvorak          #+#    #+#              #
#    Updated: 2018/06/24 17:53:00 by oshvorak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

CC = clang++

CFLAGS = -Wall -Wextra -Werror

SRC =  	./src/main.cpp \
		./src/Game.cpp \
		./src/Player.cpp \
		./src/Element.cpp \
		./src/Bullet.cpp \
		./src/Enemy.cpp \
		./src/Item.cpp

OBJS =	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -lncurses $(CFLAGS) $(SRC) -o $(NAME)
	
.cpp.o:
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
