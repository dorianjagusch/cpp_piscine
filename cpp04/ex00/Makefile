# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 17:51:52 by djagusch          #+#    #+#              #
#    Updated: 2023/08/23 18:27:51 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES := Animal \
	Dog \
	Cat \
	WrongAnimal \
	WrongCat

SRC = $(addsuffix .cpp,$(FILES) main)
INC = $(addsuffix .hpp,$(FILES))

NAME = animal

all: $(NAME)

$(NAME): $(SRC) $(INC)
	@c++ -Wall -Werror -Wextra -Wshadow -std=c++98 $(SRC) -o $@

clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re