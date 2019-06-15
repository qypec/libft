/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthtab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:40:07 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/16 00:12:53 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"
# include <stdio.h>

void					ft_puthtab(ht_list **htab)
{
	int					i;
	ht_list				*tmp;

	i = 0;
	while (i < g_htabsize)
	{
		if (htab[i]->key == NULL && htab[i]->value == NULL)
		{
			i++;
			continue ;
		}
		printf("[%d] key: |%s| value: |%s|\n", i, htab[i]->key, (char *)htab[i]->value);
		tmp = htab[i];
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			printf("-> [%d] key: |%s| value: |%s|\n", i, tmp->key, (char *)tmp->value);
		}
		i++;
	}
	printf("\n");
}