# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 15:26:58 by djagusch          #+#    #+#              #
#    Updated: 2023/08/24 16:00:04 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := Account \
	tests

SRC := $(addsuffix .cpp,$(SRC))

NAME = account

all: $(NAME)

$(NAME): $(SRC)
	@c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $@

clean:

fclean: clean
	@/bin/rm $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re