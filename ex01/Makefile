# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 21:20:07 by gabriel           #+#    #+#              #
#    Updated: 2024/01/11 08:27:22 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook
SRCS		= Contact.cpp PhoneBook.cpp PhoneBookMenu.cpp main.cpp
OBJS		= $(SRCS:.cpp=.o)

COMPILER 	= c++ -c
LINKER		= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++98
CLEANUP		= rm -rf


all: $(NAME)

$(NAME): $(OBJS)
	$(LINKER) $^ -o $@

%.o : %.cpp
	$(COMPILER) $< $(CFLAGS) -o $@ 

clean:
	$(CLEANUP) $(OBJS)
	$(CLEANUP) *.gch

fclean: clean
	$(CLEANUP) $(NAME)

re: fclean all

.PHONY: all clean fclean re
