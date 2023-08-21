# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 22:54:58 by djagusch          #+#    #+#              #
#    Updated: 2023/08/21 22:55:20 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := main \
	Harl

SRC := $(addsuffix .cpp,$(SRC))

NAME = harl

all: $(NAME)

$(NAME): $(SRC)
	@c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $@
clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re