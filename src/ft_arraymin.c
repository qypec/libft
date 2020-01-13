/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraymin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:39:37 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/10 17:38:12 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t                 ft_arraymin(size_t *arr, size_t size)
{
    size_t          i;
    size_t          tmp;

    i = 0;
    tmp = 0;
    while (i < size)
    {
        if (arr[i] < arr[tmp])
            tmp = i;
        i++;
    }
    return (tmp);
}
