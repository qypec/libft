/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrsnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:38:46 by qypec             #+#    #+#             */
/*   Updated: 2019/11/19 16:10:27 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a string array
**
** @param 		matr_size						number of strings
** @param 		line_size						size of strings
** @return		matr							pointer to a string array
*/

char				**ft_matrsnew(size_t matr_size, size_t line_size)
{
	char			**matr;
	int				i;

	if ((matr = (char **)malloc(sizeof(char *) * (matr_size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < (int)matr_size)
	{
		if ((matr[i++] = (char *)ft_memalloc(sizeof(char) * \
												(line_size + 1))) == NULL)
		{
			ft_matrdel(&matr);
			return (NULL);
		}
	}
	matr[i] = NULL;
	return (matr);
}
