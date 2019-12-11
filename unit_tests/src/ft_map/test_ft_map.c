#include "unit_test.h"

static int				test_hashfunc(const char *str, size_t mapsize)
{
	return (ft_strlen(str) % mapsize);
}

static void				test_valuedel(void **value)
{
	ft_strdel((char **)value);
}

void					test_ft_map(void)
{
	t_map				*map;

	ft_printf("{yellow}Check ft_map:{reset}\n\n");

/* Case 01 ft_mapinit */

	ft_printf("{blue}Case 01 [ft_mapinit] -------------{reset}\n\n");
	map = ft_mapinit(100, test_hashfunc, test_valuedel);
	if (map->size == 100 && map->hashfunc == &test_hashfunc && map->valuedel_func == &test_valuedel)
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_map(&map);

}
