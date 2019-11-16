/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffaddsymb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:36:28 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/16 15:57:04 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds a symbol to the buffer. 
** If there is not enough memory, then realloc it.
**
** @param 		c		symbol to be added to the buffer
** @return		N/A
*/

void					ft_buffaddsymb(t_buff *buff, char c)
{
	size_t				size_of_new_str;
	size_t				remaining_size;

	remaining_size = buff->totalsize - buff->size;
	size_of_new_str = 1;
	if (remaining_size <= size_of_new_str)
	{
		buff->totalsize += size_of_new_str + buff->additional_size;
		if ((buff->line = ft_realloc(buff->line, buff->totalsize)) == NULL)
			exit(1);
	}
	buff->line[buff->size] = c;
	buff->size += size_of_new_str;
}
