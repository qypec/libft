/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:42:23 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/19 16:17:52 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns pointer to the new string array (copy matr)
**
** @param 		matr
** @return		newmatr		pointer to the new array of strings
*/

char				**ft_matrdup(const char **matr)
{
	char			**newmatr;
	size_t			matr_size;
	int				i;

	matr_size = ft_matrlen(matr);
	if ((newmatr = (char **)malloc(sizeof(char *) * (matr_size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < (int)matr_size)
	{
		newmatr[i] = ft_strdup(matr[i]);
		i++;
	}
	newmatr[i] = NULL;
	return (newmatr);
}
