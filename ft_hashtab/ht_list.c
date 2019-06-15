/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:30:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/16 01:42:39 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"

void					ht_listdelone(ht_list **list)
{
	ht_list				*tmp;

	if (list == NULL)
		return ;
	tmp = *list;
	tmp = tmp->next;
	(*list)->next = tmp->next;
	tmp->next = NULL;
	free(tmp);
	tmp = NULL;
}

void					ht_listdel(ht_list **list)
{
	ht_list				*tmp;

	tmp = *list;
	while (tmp != NULL)
		ht_listdelone(&tmp);
	*list = NULL;
}

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
