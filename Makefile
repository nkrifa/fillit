# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/13 18:55:37 by nkrifa            #+#    #+#              #
#    Updated: 2017/05/13 18:55:57 by nkrifa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRC_PATH = ./
OBJ_PATH = ./obj/
INC_PATH = ./includes

NAME = fillit

SRC_NAME = check.c\
		   main.c\
		   algo.c\
		   ft_fillmap.c\
		   map.c\
		   move_up_left.c\
		   ft_stock.c

TMP = tmp.txt

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[33mCompilation OBJ done !\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	@echo "\033[32mCompilation EXE done !\033[0m"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

r : run

run :
	@echo "\033[32mRunning program :\033[35m $(NAME)\033[0m"
	./$(NAME) | less

s : save

save :
	@echo "\033[32mRunning program :\033[35m $(NAME)\033[0m saving results in $(TMP) file"
	./$(NAME) >> $(TMP)

clean:
	@rm -rfv $(OBJ_PATH)
	@rm -f $(TMP)
	@echo "\033[36mClean !\033[0m"

fclean : clean
	@rm -fv $(NAME)

re : clean all
