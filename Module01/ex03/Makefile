# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 14:33:08 by tmarts            #+#    #+#              #
#    Updated: 2023/09/04 14:35:01 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= violence
CPP			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
SRC			= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
INC			= Weapon.hpp HumanA.hpp HumanB.cpp
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
	rm -rf $(NAME)
re : fclean all

.PHONY : clean, fclean, all, re