/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:11:07 by qypec             #+#    #+#             */
/*   Updated: 2019/11/19 16:18:50 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees the string array.
**
** @param 		ret
** @return		N/A
*/

void				*ft_matrdel(char ***ret)
{
	char	**tmp;
	int		i;

	if (*ret == NULL)
		return (NULL);
	tmp = *ret;
	i = 0;
	while (tmp[i] != NULL)
	{
		ft_strdel(&tmp[i]);
		i++;
	}
	free(tmp);
	tmp = NULL;
	*ret = tmp;
	return (NULL);
}
