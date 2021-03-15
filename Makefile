##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for the ex00
##

DIR		=	src/

DIR_TESTS	=	tests/

SRC_TESTS	=	$(DIR_TESTS)test.cpp  \
			$(DIR)trade.cpp

OBJ_TESTS	=	$(SRC_TESTS:.cpp=.o)

SRC		=	$(DIR)main.cpp	\
			$(DIR)trade.cpp

OBJ 		= 	$(SRC:.cpp=.o)

CPPFLAGS 	=	-I./include -Wall -Wextra

FLAGS_SFML	=	-lsfml-graphics -lsfml-window -lsfml-system

CC		=	g++

RM		=	rm -f

NAME		=	trade

NAME_TESTS	=	unit_tests

LIB_CRITERION	=	-lcriterion --coverage

%.o: %.cpp
			@$(CC) $(CPPFLAGS) -c $< -o $@
			@printf "[\033[0;32mCopiled\033[0m] % 30s\n" $< | tr ' ' '.'

all:			$(NAME)

$(NAME):		$(OBJ)
			@printf "[\033[0;33mBuild\033[0m] % 32s\n" $(NAME) | tr ' ' '.'
			@$(CC) -o $(NAME) $(OBJ)

tests_run:		fclean $(OBJ_TESTS)
			@$(CC) $(CPPFLAGS) -o $(NAME_TESTS) $(SRC_TESTS) $(LIB_CRITERION)
			@$(RM) $(OBJ_TESTS)
			@./$(NAME_TESTS)

rm_tests:
			@printf "[\033[0;31mDeleted\033[0m] % 30s\n" $(NAME_TESTS) | tr ' ' '.'
			@$(RM) $(NAME_TESTS)
			@$(RM) *.gcda
			@$(RM) *.gcno

clean:
			@printf "[\033[0;31mDeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'
			@printf "[\033[0;31mDeleted\033[0m] % 30s\n" $(NAME_BONUS) | tr ' ' '.'
			@printf "[\033[0;31mDeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'
			@printf "[\033[0;31mDeleted\033[0m] % 30s\n" $(OBJ_BONUS) | tr ' ' '.'
			@$(RM) $(NAME)
			@$(RM) $(NAME_BONUS)
			@$(RM) $(OBJ)
			@$(RM) $(OBJ_BONUS)

fclean:			rm_tests clean

re:			fclean all

debug:			CFLAGS	+=	-g3
debug:			re

.PHONY:			tests_run rm_tests fclean re
