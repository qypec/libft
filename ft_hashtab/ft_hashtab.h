/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:54:23 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/15 21:04:03 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHTAB
# define FT_HASHTAB

# include							"../includes/libft.h"
# include							<stdarg.h>

# define DEFAULT_HASHTABLE_SIZE		100
# define DEFAULT_HASHFUNC			&ft_hashfunc

typedef struct						s_htablist
{
	char							*key;
	void							*value;
	struct s_htablist				*next;
}									ht_list;

int									g_htabsize;
void								*g_hashfunc;

ht_list								*ht_listnew(const char *key, const void *value);
int									ft_hashfunc(const char *str);
ht_list								**ft_htabnew(void *format, ...);
ht_list								**ft_htabadd(ht_list **htab, const char *key, const void *value);
void								ft_puthtab(ht_list **htab);

#endif