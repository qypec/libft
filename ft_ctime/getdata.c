/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:26:35 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/03 23:54:03 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctime.h"

static int	leapsyear(int year)
{
	if ((year % 4 == 0 && year % 100) || year % 400 == 0)
		return (366);
	return (365); 
}

static int	daysinmonth(t_cdate *date, int month)
{
	int num;

	if (month == 2)
	{
		if (leapsyear(date->year_n) == 366)
			num = 29;
		else
			num = 28;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || \
		month == 10 || month == 12)
		num = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		num = 30;
	return (num);
}

t_cdate		*getmonth(t_cdate *date)
{
	int	month;
	int	day;

	month = 0;
	day = 0;
	while (day < date->day_n)
	{
		month++;
		day += daysinmonth(date, month);
	}
	date->month_n = month;
	date->day_n = daysinmonth(date, month) -  (day - date->day_n);
	// printf("month = %d\n", month);
	// printf("date->day_n = %d\n", date->day_n);
	return (date);
}

t_cdate		*getyear(t_cdate *date, time_t ttime)
{
	int		tmp;
	int		day;
	int		year;

	day = 0;
	year = START_YEAR - 1;
	tmp = ((int)ttime) / (60 * 60 * 24);
	while (day <= tmp)
	{
		year++;
		day += leapsyear(year);
	}
	// if (tmp == 0)
	// 	date->day_n = leapsyear(year) - (day - tmp) + 1;
	date->day_n = leapsyear(year) - (day - tmp) + 1;
	date->year_n = year;
	return (date);
}

t_cdate		*gettime(t_cdate *date, const time_t *res)
{
	time_t	min;
	time_t	sec;
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
