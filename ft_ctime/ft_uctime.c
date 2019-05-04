#include "ft_ctime.h"

static void			print_struct(t_cdate *date)
{
	printf("---------------------------------------------\n");
	printf("print struct:\n\n");
	printf("weekday = %s\nweekday_n = %d\n\n", date->weekday, date->weekday_n);
	printf("month = %s\nmonth_n = %d\n\n", date->month, date->month_n);
	printf("day = %s\nday_n = %d\n\n", date->day, date->day_n);
	printf("hour = %s\nhour_n = %d\n\n", date->hour, date->hour_n);
	printf("min = %s\nmin = %d\n\n", date->min, date->min_n);
	printf("sec = %s\nsec_n = %d\n\n", date->sec, date->sec_n);
	printf("year = %s\nyear_n = %d\n\n", date->year, date->year_n);
	printf("---------------------------------------------\n\n");
}

static t_cdate		*nullifydate()
{
	t_cdate *date;

	date = (t_cdate *)ft_memalloc(1);
	date->weekday = NULL;
	date->weekday_n = 0;
	date->month = NULL;
	date->month_n = 0;
	date->day = NULL;
	date->day_n = 0;
	date->hour = NULL;
	date->hour_n = 0;
	date->min = NULL;
	date->min_n = 0;
	date->sec = NULL;
	date->sec_n = 0;
	date->year = NULL;
	date->year_n = 0;
	return (date);
}

void				free_uctime(t_cdate *date)
{
	if (date->weekday != NULL)
		ft_strdel(&(date->weekday));
	if (date->month != NULL)
		ft_strdel(&(date->month));
	if (date->day != NULL)
		ft_strdel(&(date->day));
	if (date->hour != NULL)
		ft_strdel(&(date->hour));
	if (date->min != NULL)
		ft_strdel(&(date->min));
	if (date->sec != NULL)
		ft_strdel(&(date->sec));
	if (date->year != NULL)
		ft_strdel(&(date->year));
	free(date);
	date = NULL;
}

t_cdate				*ft_uctime(const time_t *ttime)
{
	time_t		tsec;
	t_cdate		*date;
	time_t		res;

	tsec = (time_t)*ttime + DEL_CTIME_UNIX_SYS;
	res = 0;
	date = nullifydate();
	date = getday_since1970(date, tsec, &res); /* date->day_n since 1970 year */
	date = getweekday(date, (const time_t *)&res);
	date = gettime(date, (const time_t *)&res);
	date = getyear(date, tsec);
	date = getmonth(date);
	date = struct_to_str(date);
	print_struct(date);
	// printf("res = %ld\n", res);
	return (date);
}