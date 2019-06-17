/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:11:11 by qypec             #+#    #+#             */
/*   Updated: 2019/06/17 23:50:30 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"

void					ft_htabfree(ht_list ***htab)
{
	int					i;
	ht_list				**tmp;

	i = 0;
	tmp = *htab;
	while (i < g_htabsize)
	{
		ht_listdel(&tmp[i]);
		i++;
	}
	free(*htab);
	*htab = NULL;
}
