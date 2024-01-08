# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 21:20:07 by gasouza           #+#    #+#              #
#    Updated: 2024/01/08 06:03:02 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone
SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)

COMPILER 	= c++ -c
LINKER		= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++98
CLEANUP		= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(LINKER) $< -o $@

%.o : %.cpp
	$(COMPILER) $< $(CFLAGS) -o $@ 

clean:
	$(CLEANUP) $(OBJS)

fclean: clean
	$(CLEANUP) $(NAME)

re: fclean all

.PHONY: all clean fclean re
