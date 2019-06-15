/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:19:38 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/15 22:14:22 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"
# include <unistd.h>
# include <stdio.h>

// int						checker(void)
// {
// 	write(1, "blalba\n", 6);
// 	return (1);
// }

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
	if ((h_tab = (ht_list **)malloc(sizeof(ht_list *) * (g_htabsize + 1))) == NULL)
		return (NULL);
	while (i < g_htabsize)
		h_tab[i++] = ht_listnew(NULL, NULL);
	return (h_tab);
}

// int main()
// {
// 	ht_list		**htab;

// 	htab = ft_htabnew((void*)1, &ft_hashfunc);
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "cd", "2");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "cd", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "env", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "unsetenv", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "pwd", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "ls -l", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "ls", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "ls", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "gafghadfg", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "fgdsg", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "g", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "gafg", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "lga", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "lsjhl", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "ls546", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "ls45363", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "lsse5x", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "lae56s", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "56a3ls", "1");
// 	ft_puthtab(htab);
// 	htab = ft_htabadd(htab, "lse75rs", "1");
// 	ft_puthtab(htab);
// }