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

static void			map_insert(t_map **map, const char *key, void *value)
{
	t_list			**maplst;
	void			(*valuedel)(void **);
	int				(*hashfunc)(const char *, int );

	hashfunc = (*map)->hashfunc;
	maplst = &((*map)->array[hashfunc(key, (*map)->size)]);
	while (*maplst != NULL)
	{
		if (ft_strequ(((t_htab *)((*maplst)->content))->key, key))
		{
			valuedel = (*map)->valuedel_func;
			valuedel(&(((t_htab *)((*maplst)->content))->value));
			((t_htab *)((*maplst)->content))->value = value;
			return ;
		}
		maplst = &(*maplst)->next;
	}
	*maplst = ft_lstnew(init_htab(key, value), sizeof(t_htab *));
	(*map)->numof_items++;
	if (((*map)->numof_items / (double)(*map)->size) > 0.6)
		map_reindexing(map);
}

void				create_map(t_map **map, const char *input)
{
	char			**items;
	char			**key_value;
	const char		*key;
	size_t			i;

	items = ft_strsplit(input, '|');
	i = 0;
	while (items[i] != NULL)
	{
		key_value = ft_strsplit(items[i], ' ');
		key = key_value[0];
		map_insert(map, key, ft_strdup(key_value[1]));
		ft_matrdel(&key_value);
		i++;
	}
	ft_matrdel(&items);
}
