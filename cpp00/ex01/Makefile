# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 16:03:39 by djagusch          #+#    #+#              #
#    Updated: 2023/08/20 22:14:36 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := PhoneBook \
	Contact \

SRC := $(addsuffix .cpp,$(SRC) main)

NAME = phonebook

all: $(NAME)

$(NAME): $(SRC)
	@c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $@ -g

clean:

fclean: clean
	@/bin/rm $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re