/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:26:35 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/03 21:51:24 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctime.h"

t_cdate		*gettime(t_cdate *date, const time_t *res)
{
	time_t	min;
	time_t	sec;
	time_t	tmp;
	time_t	hour;

	min = *res / 60;
	sec = *res - (min * 60);
	hour = min / 60;
	min = min - (hour * 60);
	// printf("min = %ld\n", min);
	// printf("sec = %ld\n", sec);
	// printf("hour = %ld\n", hour);
	date->hour_n = (int)hour;
	date->min_n = (int)min;
	date->sec_n = (int)sec;
	return (date);
}

t_cdate		*getweekday(t_cdate *date, const time_t *res)
{
	time_t	weekday;
	time_t	tmp;

	weekday = date->day_n / 7;
	tmp = date->day_n - (weekday * 7);
	date->weekday_n = WEEKDAY_OF_JANUARY_1ST_1970 + tmp;
	if (date->weekday_n > 7)
		date->weekday_n -= 7;
	// printf("res = %ld\n", *res);
	// printf("date->weekday = %d\n", date->weekday_n);
	return (date);		
}

static int	multiply_coeff(int coefficient[], int i)
{
	time_t	tmp;
	int		j;

	tmp = 1;
	j = i;
	while (j--)
		tmp *= coefficient[j];
	return (tmp * coefficient[i]);
}

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
			*res += multiply_coeff(coefficient, i) * ttime;
		else
		{
			if (ttime - (tmp * coefficient[i + 1]) != 0)
				*res += multiply_coeff(coefficient, i) * (ttime - (tmp * coefficient[i + 1]));
		}
		ttime = tmp;
		i++;
	}
	date->day_n = tmp;
	return (date);
}