/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digitline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:01:53 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/19 13:46:00 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int                 ft_is_digitline(const char *line)
{
	size_t			i;

	i = 0;
	while (line[i] != 0)
	{
		if (!ft_isdigit(line[i]) && line[i] != '+' && line[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
