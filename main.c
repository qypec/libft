#include "includes/libft.h"
# include <stdio.h>

int main()
{
	time_t 	ttime;
	t_cdate	*date;

	ttime = time(NULL);
	// ttime = 0;
	// ttime = 1440;
	// ttime = 94867200;
	// ttime = 12960000;
	// ttime = 14970000;
	// ttime = 24970000;
	// ttime = 27970000;
	// ttime = 31970000;
	// ttime = 29970000;
	printf("real date:\n	%s\n", ctime(&ttime));
	date = ft_uctime(&ttime);

	return (0);
}