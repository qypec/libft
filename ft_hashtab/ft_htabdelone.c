/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 00:19:28 by qypec             #+#    #+#             */
/*   Updated: 2019/06/16 01:07:02 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"
# include <unistd.h>

void					ft_htabdelone(ht_list **htab, const char *key)
{
	int					hash;
	int					(*hash_func)(const char *);
	ht_list				*tmp;
	ht_list				*prev;

	hash_func = g_hashfunc;
	hash = hash_func(key);
	tmp = htab[hash];
	if (tmp->next == NULL)
	{
		tmp->key = NULL;
		tmp->value = NULL;
		return ;
	}
	while (tmp != NULL)
	{
		if (ft_strcmp((const char *)tmp->key, key) == 0)
			ht_listdelone(&prev);
		prev = tmp;
		if (tmp->next == NULL)
			return ;
		tmp = tmp->next;
	}
}
