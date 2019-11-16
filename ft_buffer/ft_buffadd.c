/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:36:28 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/16 16:21:06 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds a line to the buffer. 
** If there is not enough memory, then realloc it.
**
** @param 		str		string to be added to the buffer
** @return		N/A
*/

void					ft_buffadd(t_buff *buff, const char *str)
{
	size_t				size_of_new_str;
	size_t				remaining_size;

	if (str == NULL)
		return ;
	remaining_size = buff->totalsize - buff->size;
	size_of_new_str = ft_strlen(str);
	if (remaining_size <= size_of_new_str)
	{
		buff->totalsize += size_of_new_str + buff->additional_size;
		if ((buff->line = ft_realloc(buff->line, buff->totalsize)) == NULL)
			exit(1);
	}
	ft_strlglue(buff->size, buff->line, str, NULL);
	buff->size += size_of_new_str;
}

/*
** Adds a line to the buffer. 
** If there is not enough memory, then realloc it.
**
** @param 		str		string to be added to the buffer
** @param 		len		size of str
** @return		N/A
*/

void					ft_buffladd(t_buff *buff, const char *str, int len)
{
	size_t				size_of_new_str;
	size_t				remaining_size;

	if (str == NULL)
		return ;
	remaining_size = buff->totalsize - buff->size;
	size_of_new_str = len;
	if (remaining_size <= size_of_new_str)
	{
		buff->totalsize += size_of_new_str + buff->additional_size;
		if ((buff->line = ft_realloc(buff->line, buff->totalsize)) == NULL)
			exit(1);
	}
	ft_strlglue(buff->size, buff->line, str, NULL);
	buff->size += size_of_new_str;
}
