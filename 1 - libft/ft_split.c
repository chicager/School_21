/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 19:14:58 by curreg            #+#    #+#             */
/*   Updated: 2020/05/25 23:20:18 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(const char *s, char c)
{
	int words;

	words = 0;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		words++;
	}
	return (words);
}

static int		ft_get_word_length(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void		*ft_delete_dst(char **dst, int length)
{
	if (!*dst)
		return (NULL);
	while (length >= 0)
	{
		free(dst[length]);
		dst[length--] = NULL;
	}
	free(dst);
	dst = NULL;
	return (NULL);
}

static char		**ft_get_split(char const *s, char c, char **dst)
{
	int	i;
	int	j;
	int	word_length;
	int	words;

	i = 0;
	words = ft_count_words(s, c);
	while (i < words)
	{
		j = 0;
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			word_length = ft_get_word_length(s, c);
			if (!(dst[i] = (char *)malloc((word_length + 1) * sizeof(char))))
				return (ft_delete_dst(dst, i));
			while (*s != c && *s)
				dst[i][j++] = *(s++);
			dst[i][j] = '\0';
		}
		i++;
	}
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	char	**dst;
	char	*str;

	if (!s || !(str = ft_strtrim(s, &c)))
		return (NULL);
	if (!(dst = (char **)malloc((ft_count_words(str, c) + 1) * sizeof(char *))))
		return (NULL);
	dst[ft_count_words(str, c)] = NULL;
	dst = ft_get_split(str, c, dst);
	free(str);
	return (dst);
}
