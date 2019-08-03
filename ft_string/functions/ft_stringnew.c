/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:59:20 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/03 23:06:42 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string				*ft_stringnew(size_t size)
{
	t_string			*newstr;
	int					alloc_size;

	if ((newstr = (t_string *)malloc(sizeof(t_string))) == NULL)
		return (NULL);
	alloc_size = size + SOME_ADDITIONAL_MEMORY + 1;
	if ((newstr->str = (char *)ft_memalloc(sizeof(char) * alloc_size)) == NULL)
	{
		free(newstr);
		newstr = NULL;
		return (NULL);
	}
	newstr->allocated_memory = alloc_size;
	newstr->size = size;
	newstr->additional_size = size;
	newstr->content = NULL;
	return (newstr);
}
