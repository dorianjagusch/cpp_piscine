# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 14:27:30 by djagusch          #+#    #+#              #
#    Updated: 2023/08/29 09:27:06 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := Zombie \
	newZombie \
	randomChump \
	main

SRC := $(addsuffix .cpp,$(SRC))

NAME = ex00

all: $(NAME)

$(NAME): $(SRC)
	@c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $@

clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re