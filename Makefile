# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 15:03:56 by jofilipe          #+#    #+#              #
#    Updated: 2023/03/24 12:10:34 by jofilipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
COMPILER = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIREC = libft/libft.a
CLIENT = client
SERVER = server
MANDATORYCLIENTSRC = mandatory/client.c
MANDATORYCLIENTOBJ = $(MANDATORYCLIENTSRC:%.c=%.o)
MANDATORYSERVERSRC = mandatory/server.c
MANDATORYSERVEROBJ = $(MANDATORYSERVERSRC:%.c=%.o)

#bonus
BOCLIENT = client_bonus
BOSERVER = server_bonus
BONUSCLIENTSRC = bonus/client_bonus.c
BONUSCLIENTOBJ = $(BONUSCLIENTSRC:%.c=%.o)
BONUSSERVERSRC = bonus/server_bonus.c
BONUSSERVEROBJ = $(BONUSSERVERSRC:%.c=%.o)

all: $(NAME)

$(LIBFTDIREC):
	make all -C libft

$(NAME): $(MANDATORYCLIENTOBJ) $(MANDATORYSERVEROBJ) $(LIBFTDIREC)
	$(COMPILER) $(CFLAGS) $(MANDATORYCLIENTOBJ) $(LIBFTDIREC) -o $(CLIENT)
	$(COMPILER) $(CFLAGS) $(MANDATORYSERVEROBJ) $(LIBFTDIREC) -o $(SERVER)

clean:
	make clean -C libft
	rm -f $(MANDATORYCLIENTOBJ) $(MANDATORYSERVEROBJ)
	rm -f $(BONUSCLIENTOBJ) $(BONUSSERVEROBJ)

#bonus
bonus: $(BONUSCLIENTOBJ) $(BONUSSERVEROBJ) $(LIBFTDIREC)
	$(COMPILER) $(CFLAGS) $(BONUSCLIENTOBJ) $(LIBFTDIREC) -o $(BOCLIENT)
	$(COMPILER) $(CFLAGS) $(BONUSSERVEROBJ) $(LIBFTDIREC) -o $(BOSERVER)

#clean_both
fclean: clean
	make fclean -C libft
	rm -f $(CLIENT)
	rm -f $(SERVER)
	rm -f $(BOCLIENT)
	rm -f $(BOSERVER)

re: fclean all
