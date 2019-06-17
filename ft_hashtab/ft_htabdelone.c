/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 00:19:28 by qypec             #+#    #+#             */
/*   Updated: 2019/06/18 00:13:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"

void					ft_htabdelone(ht_list **htab, const char *key)
{
	int					hash;
	int					(*hash_func)(const char *);
	ht_list				*tmp;

	hash_func = g_hashfunc;
	hash = hash_func(key);
	if (htab[hash] == NULL)
		return ;
	tmp = htab[hash];
	while (tmp != NULL)
	{
		if (ft_strcmp((const char *)tmp->key, key) == 0)
		{
			ht_listdelone(&(htab[hash]), &tmp);
			return ;
		}
		if (tmp->next == NULL)
			return ;
		tmp = tmp->next;
	}
}
