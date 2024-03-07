# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 13:35:22 by lucavall          #+#    #+#              #
#    Updated: 2024/02/18 17:21:29 by lucavall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --VARIABLES--
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CLIENT		= client
SERVER		= server
LIBFT		= ./libft/libft.a
RM			= rm -rf
SRC			= client.c server.c
OBJ			= $(SRC:.c=.o)

# --RULES--

all: $(CLIENT) $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT):
			@make -C ./libft

$(CLIENT): client.c client.o $(LIBFT)
	$(CC) $(CFLAGS) client.o $(LIBFT) -o $(CLIENT)

$(SERVER): server.c server.o $(LIBFT)
	$(CC) $(CFLAGS) server.o $(LIBFT) -o $(SERVER)

clean:
	@make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
