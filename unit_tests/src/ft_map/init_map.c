#include "unit_test.h"

static void			dellst(void *content, size_t content_size)
{
	ft_strdel(&(((t_htab *)content)->key));
	content_size = 0;
	free(content);
	content = NULL;
}

static void				delete_mapind(t_map **map, size_t index)
{
	void			(*valuedel)(void **);
	t_list			**maplst;
	t_list			*tmp;

	if (index > (*map)->size)
		return ;
	if ((*map)->array[index] == NULL)
		return ;
	maplst = &((*map)->array[index]);
	valuedel = (*map)->valuedel_func;
	while (*maplst != NULL)
	{
		valuedel(&(((t_htab *)((*maplst)->content))->value));
		tmp = (*maplst)->next;
		ft_lstdelone(maplst, dellst);
		*maplst = tmp;
		(*map)->numof_items--;
	}
	(*map)->array[index] = NULL;
}

void				delete_map(t_map **map)
{
	size_t			i;

	i = 0;
	while (i < (*map)->size)
		delete_mapind(map, i++);
	free((*map)->array);
	(*map)->array = NULL;
	(*map)->size = 0;
	(*map)->numof_items = 0;
	(*map)->valuedel_func = NULL;
	free(*map);
	*map = NULL;
}
