/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrmemalloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:50:35 by qypec             #+#    #+#             */
/*   Updated: 2020/01/03 14:09:42 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate memory for an array of strings and reset it to zero
**
** @param 		size		memory
** @return		matr		pointer to array of strings
*/

char				**ft_matrmemalloc(size_t size)
{
	char			**matr;
	int				i;

	if (size == 0)
		return (NULL);
	if ((matr = (char **)malloc(sizeof(char *) * size)) == NULL)
		return (NULL);
	i = 0;
	while (i < (int)size)
		matr[i++] = NULL;
	return (matr);
}
