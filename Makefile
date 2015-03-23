# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:39:32 by npineau           #+#    #+#              #
#    Updated: 2015/03/23 17:21:51 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fckoff
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

include $(DIRCLI)/$(CLIENT).mk

include $(DIRSRV)/$(SERVEUR).mk

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

CC		:=	clang
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
