/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:39:30 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/13 14:19:19 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *str, const char *tail, size_t n)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = ft_strlen(str);
	while (tail[i] != '\0' && i < n)
	{
		str[j] = tail[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
