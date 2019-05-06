#include "ft_hashtab.h"
#include <stdio.h>

int main()
{
	printf("%d\n", ft_hash("apple"));
	printf("%d\n", ft_hash("appla"));
	printf("%d\n", ft_hash("ba"));
}