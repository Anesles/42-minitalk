# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 16:07:58 by brumarti          #+#    #+#              #
#    Updated: 2022/12/05 17:22:11 by brumarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1			= server

NAME2			= client

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

SERVER			= f_server/main.c

CLIENT			= f_client/main.c

OBJ_SERVER		= $(SERVER:.c=.o)

OBJ_CLIENT		= $(CLIENT:.c=.o)

LIBFTPATH = ./libft/

LIBFTNAME = libft.a

all:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJ_SERVER)
	make -C $(LIBFTPATH)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFTPATH)$(LIBFTNAME) -o $(NAME1)

$(NAME2):	$(OBJ_CLIENT)
	make -C $(LIBFTPATH)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFTPATH)$(LIBFTNAME) -o $(NAME2)

clean:
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)
	cd libft && $(MAKE) clean

fclean:	clean
	rm -f $(LIBFTPATH)$(LIBFTNAME) $(NAME1) $(NAME2)

re:	fclean all