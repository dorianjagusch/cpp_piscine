# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 14:02:01 by djagusch          #+#    #+#              #
#    Updated: 2023/08/30 08:15:14 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := main \
	Fixed

SRC := $(addsuffix .cpp,$(SRC))

NAME = fixed_point

all: $(NAME)

$(NAME): $(SRC)
	@c++ -Wall -Werror -Wextra $(SRC) -o $@

clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re