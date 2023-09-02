# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 17:38:05 by tmarts            #+#    #+#              #
#    Updated: 2023/09/02 16:13:24 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= brainzzz
CPP			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
SRC			= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
INC			= Zombie.hpp
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
