/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:04:53 by curreg            #+#    #+#             */
/*   Updated: 2020/07/23 20:59:47 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char const *str);
int		get_next_line(int fd, char **line);
char	*find_remnant(char **remnant, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
char	*ft_strdup(char *src);
char	*ft_strcpy(char *dest, char *src);
void	*ft_memset(void *s, int c, size_t n);
void	search_n(char **ptr_n, char **remnant, char *buf);

#endif
