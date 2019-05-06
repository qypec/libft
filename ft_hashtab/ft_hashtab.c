/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 21:04:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/06 21:10:05 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtab.h"

unsigned int	ft_hash(char *str)
{
	unsigned int	hashval;

	hashval = 0;
	while (*str != '\0')
	{
		hashval = *str + (31 * hashval);
		str++;
	}
	return (hashval % HASHSIZE);
}