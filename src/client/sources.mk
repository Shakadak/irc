# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    client.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/14 15:49:58 by npineau           #+#    #+#              #
#    Updated: 2015/05/08 16:17:11 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCCLI	:=	client_main.c \
			client_main_loop.c \
			client_add.c \
			client_create.c \
			client_read.c \
			client_write.c \
			client_standard_input.c \
			client_x.c

OBJCLI	:=	$(SRCCLI:.c=.o)

$(DIROBJ)/%.o: $(DIRCLI)/%.c $(PHEADCLI)
	$(COMPIL)
