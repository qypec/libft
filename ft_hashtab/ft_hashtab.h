/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:54:23 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/14 18:09:07 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHTAB
# define FT_HASHTAB

# include							"../includes/libft.h"

# define HT_INIT_SIZE				5
# define DEFAULT_HASHTABLE_SIZE		100

typedef struct						s_htablist
{
	void							*key;
	void							*value;
	size_t							content_size;
	struct s_htablist				*next;
}									ht_list;

int									g_htabsize;

ht_list								*ht_listnew(const void *key, const void *value);

#endif