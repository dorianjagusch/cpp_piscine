# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 20:15:57 by djagusch          #+#    #+#              #
#    Updated: 2023/08/30 11:28:28 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := main
SRC := $(addsuffix .cpp,$(SRC))

NAME = sed

all: $(NAME)

$(NAME): $(SRC)
	@c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $@
clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
