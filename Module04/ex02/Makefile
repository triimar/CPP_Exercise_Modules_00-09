# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/17 13:33:24 by tmarts            #+#    #+#              #
#    Updated: 2023/09/17 21:24:32 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= abstract_animals
CPP			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
SRC			= main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp
INC			= AAnimal.hpp Cat.hpp Dog.hpp Brain.hpp
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