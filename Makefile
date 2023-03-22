# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 15:03:56 by jofilipe          #+#    #+#              #
#    Updated: 2023/03/16 11:01:30 by jofilipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
COMPILER = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIREC = libft/libft.a
CLIENT = client
SERVER = server
MANDCLIESRC = mandatory/client.c
MANDCLIEOBJ = $(MANDCLIESRC:%.c=%.o)
MANDSERVSRC = mandatory/server.c
MANDSERVOBJ = $(MANDSERVSRC:%.c=%.o)
#bonus

all: $(NAME)

$(LIBFTDIREC):
	make all -C libft

$(NAME): $(MANDCLIEOBJ) $(MANDSERVOBJ) $(LIBFTDIREC)
	$(COMPILER) $(CFLAGS) $(MANDCLIEOBJ) $(LIBFTDIREC) -o $(CLIENT)
	$(COMPILER) $(CFLAGS) $(MANDSERVOBJ) $(LIBFTDIREC) -o $(SERVER)

clean:
	make clean -C libft
	rm -f $(MANDCLIEOBJ) $(MANDSERVOBJ)
#bonus

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
