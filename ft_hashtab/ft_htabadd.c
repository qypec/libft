/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:42:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/18 00:13:18 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"

void					ft_htabadd(ht_list **htab, const char *key, const void *value)
{
	int					hash;
	int					(*hash_func)(const char *);
	ht_list				*tmp;

	hash_func = g_hashfunc;
	hash = hash_func(key);
	if (htab[hash] == NULL)
	{
		htab[hash] = ht_listnew(key, value);
		return ;
	}
	tmp = htab[hash];
	while (tmp != NULL)
	{
		if (ft_strcmp((const char *)tmp->key, key) == 0)
		{
			tmp->value = (void *)value;
			return ;
		}
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	tmp->next = ht_listnew(key, value);
}
