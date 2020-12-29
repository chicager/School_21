/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:29:09 by curreg            #+#    #+#             */
/*   Updated: 2020/10/20 21:29:59 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_putstr_fd(char *s, int fd);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				*ft_calloc(size_t nam, size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_putchar_fd(char c, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strtrim(char const *s1, char const *set);
int					ft_isdigit(int c);
int					ft_is_only_digit(char *str);
int					ft_is_only_spaces(char *str);
int					ft_atoi(const char *str);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_substr(char const *s, int start, size_t len);
char				**ft_split(char const *s, char c);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_skip_spaces(char *str);
void				ft_clear_arr(char **map);

#endif
