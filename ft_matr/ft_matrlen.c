/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:24:22 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/19 16:15:55 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Calculate number of strings in array
**
** @param 		matr		pointer to array of strings
** @return		len			number of string
*/

size_t					ft_matrlen(const char **matr)
{
	size_t				len;

	len = 0;
	while (*matr != NULL)
	{
		len++;
		matr++;
	}
	return (len);
}
