// # include "ft_alloc.h"
# include "../includes/libft.h"

void				*ft_realloc(void *ptr, size_t newsize)
{
	char			*new_ptr;

	if ((new_ptr = (char *)ft_memalloc(sizeof(char) * (newsize + 1))) == NULL)
		return (NULL);
	new_ptr = ft_strcpy(new_ptr, ptr);
	ft_memdel(&ptr);
	return (new_ptr);
}
