/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:51:44 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/16 16:37:59 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Initialization of the buffer structure.
**
** @param 		size	initial size
** @return		buff	pointer to buff struct
*/

t_buff					*ft_buffinit(size_t size)
{
	t_buff				*buff;

	if (size == 0)
		return (NULL);
	if ((buff = (t_buff *)malloc(sizeof(t_buff))) == NULL)
		exit(-1);
	buff->additional_size = size;
	buff->totalsize = size;
	if ((buff->line = (char *)ft_memalloc(sizeof(char) * buff->totalsize)) \
										== NULL)
		exit(-1);
	buff->size = 0;
	return (buff);
}
