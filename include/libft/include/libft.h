/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:21:10 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/19 09:57:10 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef struct s_list
{
	size_t			index;
	int				number;
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int			is_strmatch(char *s1, char *s2);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isspace(int c);
int			ft_isprint(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_basetoi(char *str, char *base);
int			ft_atoi(const char *nbr);
long long	ft_atoll(char *nptr);
float		ft_atof(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strremove(char *string, char search);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
char		**ft_strtok(char const *s, char *delim);
char		*ft_strrchr(const char *s, int c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_calloc(size_t n_items, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_bzero(void *s, size_t n);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putendl_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd);
void		*ft_memset(void *buff, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
//bonus
t_list		*ft_lstnew(void *content, int number);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif