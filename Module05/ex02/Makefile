# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 16:29:48 by tmarts            #+#    #+#              #
#    Updated: 2023/11/30 21:10:09 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bureau02
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
SRC			= main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp
INC			= Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp
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
