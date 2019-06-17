/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:48:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/18 00:37:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/libft.h"

t_list						*ft_lstnew(const void *content, size_t content_size)
{
	t_list				*list;

	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->content = (void *)content;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
