# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 14:02:01 by djagusch          #+#    #+#              #
#    Updated: 2023/08/22 21:39:12 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := main \
	ClapTrap

SRC := $(addsuffix .cpp,$(SRC))

NAME = clappy

all: $(NAME)

$(NAME): $(SRC)
	@c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $@

clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re