# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 16:11:25 by tmarts            #+#    #+#              #
#    Updated: 2023/12/23 16:15:52 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= RPN
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address
SRC			= main.cpp RPN.cpp
INC			= RPN.hpp
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
