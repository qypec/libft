/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:19:38 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/16 00:12:15 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"
# include <unistd.h>
# include <stdio.h>

ht_list					**ft_htabnew(void *format, ...)
{
	ht_list				**h_tab;
	va_list				factor;
	int					i;

	i = 0;
	va_start(factor, format);
	if (format != NULL)
	{
		g_htabsize = ((int)format) * 7;
		g_hashfunc = va_arg(factor, void *);
	}
	else
	{
		g_htabsize = DEFAULT_HASHTABLE_SIZE;
		g_hashfunc = DEFAULT_HASHFUNC;
	}
	va_end(factor);
	if ((h_tab = (ht_list **)malloc(sizeof(ht_list *) * g_htabsize)) == NULL)
		return (NULL);
	while (i < g_htabsize)
		h_tab[i++] = ht_listnew(NULL, NULL);
	return (h_tab);
}
