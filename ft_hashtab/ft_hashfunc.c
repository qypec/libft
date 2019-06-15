/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:11:40 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/15 22:12:47 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"

int        ft_hashfunc(const char *str)
{
	int			i;
	long long	hash;
	int			p;
	long long	p_pow;

	p_pow = 1;
	i = 0;
	hash = 0;
	p = 16;
	while (str[i] != '\0')
	{
		hash += (str[i] - 'a' + 1) * p_pow;
		p_pow *= p;
		i++;
	}
	hash = ft_abs(hash) % g_htabsize;
	return (hash);
}
