# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 19:54:45 by tmarts            #+#    #+#              #
#    Updated: 2023/12/22 23:43:51 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= MutantStack
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address
SRC			= main.cpp
INC			= MutantStack.hpp MutantStack.tpp
OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))
all : $(NAME)
$(OBJ_DIR)/%.o : %.cpp $(INC)
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< -o $@
$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) $^ -o $@
clean :
	rm -rf $(OBJ_DIR)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : clean, fclean, all, re
