/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:30:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/15 20:56:32 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"

ht_list					*ht_listnew(const char *key, const void *value)
{
	ht_list				*list;

	if ((list = (ht_list *)malloc(sizeof(ht_list))) == NULL)
		return (NULL);
	list->key = (char *)key;
	list->value = (void *)value;
	list->next = NULL;
	return (list);
}
