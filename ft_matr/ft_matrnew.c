/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:38:46 by qypec             #+#    #+#             */
/*   Updated: 2019/08/07 12:36:40 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_matrnew(size_t matr_size, ...)
{
	char			**matr;
	va_list			arg;
	size_t			str_size;
	int				i;

	va_start(arg, matr_size);
	if ((matr = (char **)malloc(sizeof(char *) * (matr_size + 1))) == NULL)
		return (NULL);
	i = 1;
	while (i < (int)matr_size)
	{
		str_size = va_arg(arg, size_t);
		if ((matr[i++] = (char *)ft_memalloc(sizeof(char) * (str_size + 1))) == NULL)
		{
			ft_matrdel(&matr);
			return (NULL);
		}
	}
	matr[i] = NULL;
	va_end(arg);
	return (matr);
}
