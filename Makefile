# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:39:32 by npineau           #+#    #+#              #
#    Updated: 2014/05/25 18:35:38 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fckoff
CLIENT	:=	client
SERVEUR	:=	serveur

### DIRECTORIES ###

DIRSRC	:=	sources
DIRSRV	:=	$(DIRSRC)/$(SERVEUR)
DIRCLI	:=	$(DIRSRC)/$(CLIENT)
DIROBJ	:=	objects
DIRINC	:=	includes
DIRLIB	:=	libft

### FILES ###

SRCCLI	:=	client_main.c \
			client_main_loop.c \
			client_add.c \
			client_create.c \
			client_read.c \
			client_write.c \
			client_standard_input.c \
			client_x.c

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
			server_channel.c \
			server_private_message.c \
			server_client_add.c \
			server_x.c

OBJSRV	:=	$(SRCSRV:.c=.o)
OBJCLI	:=	$(SRCCLI:.c=.o)

HEADCLI	:=	client.h
HEADSRV	:=	server.h
LIB		:=	libft.a

### PATHS ###

POBJCLI		:=	$(addprefix $(DIROBJ)/, $(OBJCLI))
POBJSRV		:=	$(addprefix $(DIROBJ)/, $(OBJSRV))
PHEADSRV	:=	$(DIRINC)/$(HEADSRV)
PHEADCLI	:=	$(DIRINC)/$(HEADCLI)
PLIB		:=	$(DIRLIB)/$(LIB)

### COMPILATION VARIABLES ###

CC		:=	llvm-gcc
C_FLAG	:=	-Wall -Wextra -Werror
O_FLAG	:=	-O3
L_FLAG	:=	-L $(DIRLIB) -lft
C_INC	:=	-I $(DIRINC) -I $(DIRLIB)/$(DIRINC)

COMPIL	=	$(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	=	$(CC) -o $@ $^ $(L_FLAG)

### RULES ###

.PHONY: all clean fclean re

all: $(PLIB) $(SERVEUR) $(CLIENT)

### LIBFT ###

$(PLIB):
	make -C $(DIRLIB)

### OBJECTS ###

$(DIROBJ):
	mkdir $(DIROBJ)

$(POBJSRV): |$(DIROBJ)

$(POBJCLI): |$(DIROBJ)

$(DIROBJ)/%.o: $(DIRCLI)/%.c $(PHEADCLI)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRSRV)/%.c $(PHEADSRV)
	$(COMPIL)

### EXECUTABLE ###

$(NAME):
	echo $(NAME)

$(CLIENT): $(POBJCLI)
	$(LINK)

$(SERVEUR): $(POBJSRV)
	$(LINK)

### CLEAN UP ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(CLIENT) $(SERVEUR)

re: fclean all
