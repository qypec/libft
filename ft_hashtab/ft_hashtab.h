/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:54:23 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/16 01:30:19 by qypec            ###   ########.fr       */
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
void								ht_listdelone(ht_list **list);
void								ht_listdel(ht_list **list);

int									ft_hashfunc(const char *str);

ht_list								**ft_htabnew(void *format, ...);
void								ft_htabadd(ht_list **htab, const char *key, const void *value);
void								ft_htabdelone(ht_list **htab, const char *key);
void								ft_htabfree(ht_list ***htab);
void								ft_puthtab(ht_list **htab);

#endif