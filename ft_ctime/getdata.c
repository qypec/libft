/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:26:35 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/03 19:42:18 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctime.h"

t_cdate		*getday(t_cdate *date, time_t ttime, time_t *res)
{
	time_t	tmp;
	int		coefficient[4];
	int		i;

	i = 0;
	tmp = 0;
	coefficient[0] = 1;
	coefficient[1] = 60;
	coefficient[2] = 60;
	coefficient[3] = 24;
	while (ttime != 0 && i != 3)
	{
		if ((tmp = ttime / coefficient[i + 1]) == 0)
			*res = ttime;
		else
		{
			if (ttime - (tmp * coefficient[i + 1]) != 0)
				*res = coefficient[i] * (ttime - (tmp * coefficient[i + 1]));
		}
		ttime = tmp;
		i++;
	}
	date->day_n = tmp;
	return (date);
}