# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:39:32 by npineau           #+#    #+#              #
#    Updated: 2015/05/08 16:18:57 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	irc
CLIENT	:=	client
SERVEUR	:=	serveur

### DIRECTORIES ###

DIRSRC	:=	src
DIRSRV	:=	$(DIRSRC)/$(SERVEUR)
DIRCLI	:=	$(DIRSRC)/$(CLIENT)
DIROBJ	:=	obj
DIRINC	:=	inc
DIRLIB	:=	libft

### FILES ###

include $(DIRCLI)/sources.mk
include $(DIRSRV)/sources.mk

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


CC		:=	clang
C_FLAG	:=	-Wall -Wextra -Werror
O_FLAG	:=	-O3
L_FLAG	:=	-L $(DIRLIB) -lft
C_INC	:=	-I $(DIRINC) -I $(DIRLIB)/$(DIRINC) -I .

COMPIL	=	$(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	=	$(CC) -o $@ $^ $(L_FLAG)

### RULES ###

.PHONY: all clean fclean re

all: $(SERVEUR) $(CLIENT)

### LIBFT ###

$(PLIB):
	make -C $(DIRLIB)

### OBJECTS ###

$(DIROBJ):
	mkdir $(DIROBJ)

$(POBJSRV): |$(DIROBJ)

$(POBJCLI): |$(DIROBJ)

### EXECUTABLE ###

$(CLIENT): $(PLIB) $(POBJCLI)
	$(LINK)

$(SERVEUR): $(PLIB) $(POBJSRV)
	$(LINK)

### CLEAN UP ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(CLIENT) $(SERVEUR)

re: fclean all

$(NAME): all
