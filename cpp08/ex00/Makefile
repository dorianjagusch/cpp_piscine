# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 15:58:53 by djagusch          #+#    #+#              #
#    Updated: 2023/09/18 12:36:21 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
XFLAGS = -g -Wconversion -Wshadow

RM = /bin/rm

FILES :=

S = src
O = obj

SRC = $(addprefix $S/,$(addsuffix .cpp,$(FILES) main))
INC = $(addprefix $S/,$(addsuffix .hpp,easyfind))
OBJ = $(patsubst $S/%,$O/%,$(SRC:.cpp=.o))
ODIR = $(dir $(OBJ))

NAME = ex00

all: $(NAME)

print:
	echo $(SRC)

$(NAME): $(OBJ) $(INC) $(SRC)
	@$(CC) $(CXXFLAGS) $(OBJ) -o $@ $(XFLAGS)
	@echo "$(COLOUR_GREEN) $@ successfully created$(COLOUR_END)"

$O:
	@mkdir -p $@ $(ODIR)

$O/%.o: $S/%.cpp $(INC) | $O
	@$(CC) $(CXXFLAGS) -c $< $(XFLAGS) -o $@

clean:
	@$(RM) -f $(OBJ)
	@if [ -d $O ]; then $(RM) -rf $(O_DIRS) $O; fi
	@echo "$(COLOUR_RED) .o-files removed$(COLOUR_END)"

fclean: clean
	@$(RM) -f $(NAME)
		@echo "$(COLOUR_RED) $(NAME) removed$(COLOUR_END)"

re: fclean $(NAME)

.PHONY: all clean fclean re