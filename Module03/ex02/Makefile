# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 18:57:54 by tmarts            #+#    #+#              #
#    Updated: 2023/09/21 21:09:22 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Frag
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
# CPPFLAGS	+= -g3 -fsanitize=address
SRC			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
INC			= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))
all : $(NAME)
$(OBJ_DIR)/%.o : %.cpp $(INC)
	@mkdir -p $(dir $@)
	$(CPP) $(FLAGS) -c $< -o $@
$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $^ -o $@
clean : 
	rm -rf $(OBJ_DIR)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : clean, fclean, all, re
