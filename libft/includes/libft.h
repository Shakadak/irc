/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:00:59 by npineau           #+#    #+#             */
/*   Updated: 2014/05/23 12:34:11 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

# define BUFF_SIZE 32

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *src);
char				*ft_itoa(int n);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(char c);
int					ft_tolower(int c);
int					ft_toupper(int c);

void				ft_array_free(void ***array);
void				ft_bzero(void *src, size_t length);
void				*ft_memchr(const void *ptr, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *dest, int c, size_t length);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

char				*ft_strchr(const char *src, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strcpy(char *copy, const char *src);
char				*ft_strncpy(char *copy, const char *src, size_t n);
char				*ft_strstr(const char *dest, const char *mod);
char				*ft_strnstr(const char *dest, const char *mod, size_t n);
char				*ft_strrchr(const char *src, int c);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t buf);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **ap);
void				ft_strclr(char *src);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *src, unsigned int start, size_t n);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *src);
char				**ft_strsplit(char const *s, char c);
int					get_next_line(int fd, char **src);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
