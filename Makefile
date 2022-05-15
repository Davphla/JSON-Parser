##
## EPITECH PROJECT, 2020
## rpg
## File description:
## Makefile
##

CFLAGS 			=  --std=gnu99 -Wextra -Wall -g3 -fvisibility=hidden
CPPFLAGS		= 	-I ./inc

SRC		:=		$(shell find src/ -name "*.c" -type f)

OBJ		:=	$(SRC:.c=.o)

NAME	=	libjson.a

all:	$(NAME)
	@echo "Build succesfull!"

$(NAME):  $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
