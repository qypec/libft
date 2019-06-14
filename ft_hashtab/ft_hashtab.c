/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:23:35 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/14 18:13:58 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_hashtab.h"
# include <stdio.h>
# include <unistd.h>

int        hash_for_builtin_name(char *str)
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
	hash %= g_htabsize;
	return (hash);
}

ht_list					*ft_htabnew(void)
{
	ht_list				*h_tab;
	int					i;

	i = 0;
	g_htabsize = DEFAULT_HASHTABLE_SIZE;
	h_tab = (ht_list *)malloc(sizeof(ht_list) * HT_INIT_SIZE);
	while (i < HT_INIT_SIZE)
		h_tab[i++] = *ht_listnew(NULL, NULL);
	return (h_tab);
}

void					ft_htab_insert(ht_list *htab, const void *key, const void *value)
{
	htab[0].key = (void *)key;
	htab[0].value = (void *)value;
}

// char					*checker(void)
// {
// 	write(1, "hello\n", 6);
// 	return ("asda");
// }

int						main()
{
	ht_list				*h_tab;
	// char				(*message)(void);

	h_tab = ft_htabnew();
	ft_htab_insert(h_tab, (void *)"cd", (void *)&checker);
	printf("key = %s\n", (char *)h_tab[0].key);
	// message = h_tab[0].value;
	// message();
	// printf("value = %p\n", h_tab[0].value);
}