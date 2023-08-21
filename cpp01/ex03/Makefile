# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 17:22:19 by djagusch          #+#    #+#              #
#    Updated: 2023/08/21 18:42:21 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := main \
	Weapon \
	HumanA \
	HumanB

SRC := $(addsuffix .cpp,$(SRC))

NAME = ex03

all: $(NAME)

$(NAME): $(SRC)
	@c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $@ -fsanitize=address -static-libasan

clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re