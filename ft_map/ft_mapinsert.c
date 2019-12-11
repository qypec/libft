/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:15:43 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/11 16:11:23 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

/*
** Inserts a value of a hash table by key.
** If a value for this key already exists, the function replace it.
**
** @param 		key
** @param 		value
** @return		N/A
*/

void				ft_mapinsert(t_map **map, const char *key, void *value)
{
	t_list			**maplst;
	void			(*valuedel)(void **);
	int				(*hashfunc)(const char *, int );

	hashfunc = (*map)->hashfunc;
	maplst = &((*map)->array[hashfunc(key, (*map)->size)]);
	while (*maplst != NULL)
	{
		if (ft_strequ(((t_htab *)((*maplst)->content))->key, key))
		{
			valuedel = (*map)->valuedel_func;
			valuedel(&(((t_htab *)((*maplst)->content))->value));
			((t_htab *)((*maplst)->content))->value = value;
			return ;
		}
		maplst = &(*maplst)->next;
	}
	*maplst = ft_lstnew(init_htab(key, value), sizeof(t_htab *));
	(*map)->numof_items++;
	// ft_printf("")
	// ft_printf("%Lf\n", ((*map)->numof_items / (*map)->size));
	if (((*map)->numof_items / (double)(*map)->size) > 0.6)
		map_reindexing(map);
}
