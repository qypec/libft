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
	printf("real date:\n	%s\n", ctime(&ttime));
	date = ft_uctime(&ttime);

	return (0);
}