#include "unit_test.h"

static const void		*mapvalue(t_map *map, const char *key)
{
	t_list			*maplst;
	int				(*hashfunc)(const char *, int );

	hashfunc = map->hashfunc;
	maplst = map->array[hashfunc(key, map->size)];
	while (maplst != NULL)
	{
		if (ft_strequ(((t_htab *)(maplst->content))->key, key))
			return ((const void *)((t_htab *)(maplst->content))->value);
		maplst = maplst->next;
	}
	return (NULL);
}

static int				is_mapitem(t_map *map, const char *key)
{
	if (mapvalue(map, key) == NULL)
		return (0);
	return (1);
}

int						compare_maps(t_map **map, const char *expected)
{
	int					returned_code;
	char				**expected_items;
	char				**expect_key_value;
	size_t				expected_size;

	returned_code = 1;
	expect_key_value = NULL;
	expected_items = ft_strsplit(expected, '|');
	expected_size = ft_matrlen((const char **)expected_items);
	if ((*map)->numof_items == expected_size)
	{
		while (expected_size--)
		{
			expect_key_value = ft_strsplit(expected_items[expected_size], ' ');
			if (!is_mapitem(*map, expect_key_value[0]))
			{
				returned_code = 0;
				break ;
			}
			ft_matrdel(&expect_key_value);
		}
	}
	else
		returned_code = 0;
	ft_matrdel(&expect_key_value);
	ft_matrdel(&expected_items);
	return (returned_code);
}
