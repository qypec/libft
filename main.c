#include "includes/libft.h"
# include <stdio.h>

int main()
{
	time_t ttime;

	ttime = time(NULL);
	printf("real date:\n	%s\n", ctime(&ttime));
	ft_ctime(ttime);

	return (0);
}