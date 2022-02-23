# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 12:58:37 by pwildcat          #+#    #+#              #
#    Updated: 2022/02/23 12:58:39 by pwildcat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = minitalk

SRCS = server.c client.c
SRCS1 = server.c
SRCS2 = client.c

HEADER = mini.h

OBJ	=	$(SRCS:%.c=%.o)

CFLAGS	= -Wall -Wextra -Werror -I$(HEADER)

all : server client
server :	$(SRCS1)
		gcc $(CFLAGS) $< -o $@
client : $(SRCS2)
		gcc $(CFLAGS) $< -o $@
bonus : server_bonus client_bonus
server_bonus :	$(SRCS1)
		gcc $(CFLAGS) -c $< -o $@
client_bonus : $(SRCS2)
		gcc $(CFLAGS) -c $< -o $@
clean	:
	rm -f $(OBJ)
fclean	:	clean
	rm -f client server server_bonus client_bonus
re		:	fclean all
re_bonus : fclean bonus
.PHONY	:	all clean fclean re bonus re_bonus

