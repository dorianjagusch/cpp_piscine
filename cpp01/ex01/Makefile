# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 14:27:30 by djagusch          #+#    #+#              #
#    Updated: 2023/08/21 17:03:50 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := Zombie \
	zombieHorde \
	main

SRC := $(addsuffix .cpp,$(SRC))

NAME = ex01

all: $(NAME)

$(NAME): $(SRC)
	@c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $@

clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re