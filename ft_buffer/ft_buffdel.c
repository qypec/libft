/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:36:22 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/19 13:06:15 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees the buffer structure.
**
** @param 		buff	pointer to structure
** @return		N/A
*/

void					ft_buffdel(t_buff **buff)
{
	ft_strdel(&((*buff)->line));
	(*buff)->size = 0;
	(*buff)->totalsize = 0;
	(*buff)->additional_size = 0;
	free(*buff);
	buff = NULL;
}
