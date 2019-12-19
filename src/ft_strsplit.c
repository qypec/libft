/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:13:16 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/18 15:43:01 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				get_split_len(char **str, int c)
{
	size_t			len;
	char			*s;
	
	while (**str == c && **str != '\0')
		(*str)++;
	s = *str;
	len = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			len++;
			while (*s == c && *s != '\0')
				s++;
		}
		s += ((*s == '\0') ? 0 : 1);
	}
	return (((len == 0) ? 0 : len));
}

char				**ft_strsplit(char const *s, char c)
{
	char			**matr;
	const char 		*c_ptr;
	size_t			len;
	size_t			i;

	if ((matr = (char **)ft_matrmemalloc(sizeof(char *) * \
			(get_split_len((char **)&s, c)))) == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if ((c_ptr = ft_strchr(s, c)) == NULL)
			len = ft_strlen(s);
		else
			len = c_ptr - s;
		if ((matr[i] = ft_strnew(sizeof(char) * (len + 1))) == NULL)
			return (ft_matrdel(&matr));
		ft_memcpy(matr[i++], s, len);
		(s[len] == '\0') ? (s += len) : (s += len + 1);
		while (*s != '\0' && *s == c)
			s++;
	}
	return (matr);
}
