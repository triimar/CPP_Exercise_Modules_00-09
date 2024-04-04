# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 19:07:19 by tmarts            #+#    #+#              #
#    Updated: 2024/04/04 14:07:26 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= accounts
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
# CPPFLAGS	+= -g3 -fsanitize=address
SRC			= tests.cpp Account.cpp
INC			= Account.hpp
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