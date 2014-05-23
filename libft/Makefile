# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:15:41 by npineau           #+#    #+#              #
#    Updated: 2014/05/23 12:23:46 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a

### DIRECTORIES ###

DIRSRC		:=	sources
DIROBJ		:=	objects
DIRCHAR		:=	$(DIRSRC)/char
DIRLST		:=	$(DIRSRC)/list
DIRMEM		:=	$(DIRSRC)/memory
DIRPUT		:=	$(DIRSRC)/output
DIRSTR		:=	$(DIRSRC)/string
DIRINC		:=	includes

### FILES ###

### FILES: SOURCES ###

CHAR		:=	ft_atoi.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_itoa.c \
				ft_tolower.c \
				ft_toupper.c

LST			:=	ft_lstadd.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c

MEM			:=	ft_array_free.c \
				ft_bzero.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c

PUT			:=	ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c

STR			:=	ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c \
				get_next_line.c

### FILES: OBJECTS ###

OBJ			:=	$(CHAR:.c=.o) \
				$(LST:.c=.o) \
				$(MEM:.c=.o) \
				$(PUT:.c=.o) \
				$(STR:.c=.o)

### FILES: PATHS ###

POBJ		:=	$(addprefix $(DIROBJ)/, $(OBJ))
INC			:=	$(DIRINC)/libft.h

### ARCHIVE ###

AR			:=	ar
AR_FLAG		:=	-crus
AR_EXEC		=	$(AR) $(AR_FLAG) $@ $^

### COMPILATION ###

CC			:=	llvm-gcc
C_FLAG		:=	-Wall -Wextra -Werror
O_FLAG		:=	-O3
C_OPT		=	-o $@ -c $< -I $(DIRINC)
COMPIL		=	$(CC) $(C_FLAG) $(O_FLAG) $(C_OPT)

### RULES ###

all: $(NAME)

### RULES: COMPILATION ###

$(DIROBJ)/%.o: $(DIRCHAR)/%.c $(INC)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRLST)/%.c $(INC)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRMEM)/%.c $(INC)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRPUT)/%.c $(INC)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRSTR)/%.c $(INC)
	$(COMPIL)

### RULES: ARCHIVE ###

$(NAME): $(POBJ)
	$(AR_EXEC)

### RULES: MISC ###

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

clean:
	@(rm -f $(POBJ))

fclean: clean
	@(rm -f $(NAME))

re: fclean $(NAME)

.PHONY: all clean re fclean
