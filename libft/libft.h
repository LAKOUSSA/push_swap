/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:37:59 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 02:51:42 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

/*PART ONE*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_strlen(char *s);
int					ft_strlcpy(char *dst, char *src, int dstsize);
int					ft_strlcat(char *dst, char *src, int size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(char *s, int find);
char				*ft_strrchr(char *s, int find);
int					ft_strncmp(char *s1, char *s2, int n);
char				*ft_strnstr(char *str, char *to_find, int len);
long int			ft_atoi(char *str);
char				*ft_strdup(char *src);
/*PART TWO*/
char				*ft_substr(char *s, int start, int len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char *s1, char *set);
char				**ft_split(char *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char *s, char (*f)(int, char));
void				ft_striteri(char *s, void (*f)(int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
/*BONUS*/
t_list				*ft_lstnew(int data);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);

#endif
