#include "ft_ctime.h"

static char			*digit_to_str(int num)
{
	char	*str;
	int		len;

	len = ft_numblen(num);
	if (len < 1 || len > 2)
		return (NULL);
	if (len == 1)
	{
		str = (char *)ft_memalloc(3);
		str[0] = '0';
		str[1] = num + '0';
		str[2] = '\0';
	}
	else
		return (ft_itoa(num));
	return (str);

}

static char			*whatsmonth(int month)
{
	if (month == 1)
		return (ft_strdup("Jan"));
	if (month == 2)
		return (ft_strdup("Feb"));
	if (month == 3)
		return (ft_strdup("Mar"));
	if (month == 4)
		return (ft_strdup("Apr"));
	if (month == 5)
		return (ft_strdup("May"));
	if (month == 6)
		return (ft_strdup("Jun"));
	if (month == 7)
		return (ft_strdup("Jul"));
	if (month == 8)
		return (ft_strdup("Aug"));
	if (month == 9)
		return (ft_strdup("Sep"));
	if (month == 10)
		return (ft_strdup("Oct"));
	if (month == 11)
		return (ft_strdup("Nov"));
	if (month == 12)
		return (ft_strdup("Dec"));
	return (NULL);
}

static char			*whatsday(int weekday)
{
	if (weekday == 1)
		return (ft_strdup("Mon"));
	if (weekday == 2)
		return (ft_strdup("Tue"));
	if (weekday == 3)
		return (ft_strdup("Wed"));
	if (weekday == 4)
		return (ft_strdup("Thu"));
	if (weekday == 5)
		return (ft_strdup("Fri"));
	if (weekday == 6)
		return (ft_strdup("Sat"));
	if (weekday == 7)
		return (ft_strdup("Sun"));
	return (NULL);

}

t_cdate				*struct_to_str(t_cdate *date)
{
	date->weekday = whatsday(date->weekday_n);	
	date->month = whatsmonth(date->month_n);
	date->day = ft_itoa(date->day_n);
	date->hour = digit_to_str(date->hour_n);
	date->min = digit_to_str(date->min_n);
	date->sec = digit_to_str(date->sec_n);
	date->year = ft_itoa(date->year_n);
	return (date);
}
