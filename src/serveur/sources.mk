# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    serveur.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/14 15:51:35 by npineau           #+#    #+#              #
#    Updated: 2015/05/08 16:17:26 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSRV	:=	server_check_fd.c \
			server_clean_fd.c \
			server_client_read.c \
			server_client_write.c \
			server_do_select.c \
			server_get_opt.c \
			server_init_env.c \
			server_init_fd.c \
			server_main.c \
			server_main_loop.c \
			server_srv_accept.c \
			server_srv_create.c \
			server_command.c \
			server_nick.c \
			server_channel.c \
			server_private_message.c \
			server_client_add.c \
			server_fill_commands.c \
			server_get_command.c \
			server_x.c \
			queue_to_buffer.c

OBJSRV	:=	$(SRCSRV:.c=.o)

$(DIROBJ)/%.o: $(DIRSRV)/%.c $(PHEADSRV)
	$(COMPIL)
