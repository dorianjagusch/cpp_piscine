# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 14:02:01 by djagusch          #+#    #+#              #
#    Updated: 2023/08/23 15:27:17 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := main \
	ClapTrap \
	ScavTrap \
	FragTrap \
	DiamondTrap

SRC := $(addsuffix .cpp,$(SRC))

NAME = diamond

all: $(NAME)

$(NAME): $(SRC)
	@c++ -Wall -Werror -Wextra -Wshadow -std=c++98 $(SRC) -o $@

clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re