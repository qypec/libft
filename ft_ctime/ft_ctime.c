
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

// char	*struct_to_str(t_cdate *date)
// {
// 	print_struct(date);
// 	return (NULL);
// }

char	*ft_ctime(const time_t *ttime)
{
	t_cdate		*date;
	char		*str;

	date = ft_uctime(ttime);
	// str = struct_to_str(date);
	return (NULL);
}
