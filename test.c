#include "libft.h"
#include <stdio.h>

int					main()
{
	t_string		*output;

	output = ft_stringnew(1);
	printf("size = %zu\n", output->size);
	printf("str = %s\n", output->str);
}