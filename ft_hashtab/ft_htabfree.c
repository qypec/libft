/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:11:11 by qypec             #+#    #+#             */
/*   Updated: 2019/06/16 01:42:09 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"

void					ft_htabfree(ht_list ***htab)
{
	int					i;

	i = 0;
	while (i < g_htabsize)
		ht_listdel(htab[i++]);
	free(*htab);
	*htab = NULL;
}
