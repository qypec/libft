/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:42:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/15 22:04:08 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"
# include <stdio.h>

ht_list					**ft_htabadd(ht_list **htab, const char *key, const void *value)
{
	int					hash;
	int					(*hash_func)(const char *);
	ht_list				*tmp;

	hash_func = g_hashfunc;
	hash = hash_func(key);
	tmp = htab[hash];
	if (htab[hash]->key == NULL)
	{
		htab[hash]->key = (char *)key;
		htab[hash]->value = (void *)value;
	}
	else
	{
		while (tmp != NULL)
		{
			if (ft_strcmp((const char *)tmp->key, key) == 0)
			{
				tmp->value = (void *)value;
				return (htab);
			}
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
		}
		tmp->next = ht_listnew(key, value);
	}
	return (htab);
}
