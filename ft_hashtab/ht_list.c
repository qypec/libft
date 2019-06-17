/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:30:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/17 23:30:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"

void					ht_listdelone(ht_list **head, ht_list **list)
{
	ht_list				*tmp;

	if (*list == NULL)
		return ;
	tmp = *head;
	if (*head == *list && (*list)->next != NULL)
		*head = (*head)->next;
	if (tmp != *list)
	{
		while (tmp->next != *list)
			tmp = tmp->next;
		tmp->next = (*list)->next;
	}
	(*list)->next = NULL;
	(*list)->key = NULL;
	(*list)->value = NULL;
	free(*list);
	list = NULL;
}

void					ht_listdel(ht_list **head)
{
	ht_list				*tmp;

	if (*head == NULL)
		return ;
	tmp = *head;
	if (tmp->next == NULL)
	{
		ht_listdelone(head, &tmp);
		return ;
	}
	tmp = tmp->next;
	while (tmp != NULL)
	{
		ht_listdelone(head, &tmp);
		tmp = (*head)->next;
	}
	(*head)->next = NULL;
	(*head)->key = NULL;
	(*head)->value = NULL;
	free(*head);
	head = NULL;
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
