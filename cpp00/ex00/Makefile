# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 16:03:39 by djagusch          #+#    #+#              #
#    Updated: 2023/08/19 16:12:56 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := megaphone

SRC := $(addsuffix .cpp,$(SRC))

NAME = megaphone

all: $(NAME)

$(NAME): $(SRC)
	c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $@

clean:

fclean: clean
	/bin/rm $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re