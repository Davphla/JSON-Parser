##
## EPITECH PROJECT, 2020
## rpg
## File description:
## Makefile
##

SRC_FILES	=	checker/main_parser.c \
				checker/parser_destroy.c \
				checker/parser_element.c \
				checker/parser_tools.c \
				writer/main_writer.c \
				writer/writer_element.c \
				writer/writer_tools.c

SRC_DIR	= src/

SRC		=	$(foreach file, $(SRC_FILES), $(addprefix $(SRC_DIR), $(file)))

OBJ		=	$(SRC:.c=.o)

NAME	=	JSON_parser

CFLAGS	=	-I./include/ -Wall

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
