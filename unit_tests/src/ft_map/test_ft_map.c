#include "unit_test.h"

static int				test_hashfunc(const char *str, size_t mapsize)
{
	return (ft_strlen(str) % mapsize);
}

static void				test_valuedel(void **value)
{
	ft_strdel((char **)value);
}

static void				printvalue_str(void *value)
{
	ft_putendl((const char *)value);
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

/* Case 02 ft_mapinsert with default hashfunc */

	ft_printf("{blue}Case 02 [ft_mapinsert with default hashfunc] -------------{reset}\n\n");
	map = ft_mapinit(10, NULL, test_valuedel);
	create_map(&map, "1 a|2 b|3 c");
	ft_mapinsert(&map, "4", ft_strdup("d"));
	if (compare_maps(&map, "1 a|2 b|3 c|4 d"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_map(&map);

/* Case 03 ft_mapinsert with own hashfunc */

	ft_printf("{blue}Case 03 [ft_mapinsert with own hashfunc] -------------{reset}\n\n");
	map = ft_mapinit(10, test_hashfunc, test_valuedel);
	create_map(&map, "1 a|2 b|3 c");
	ft_mapinsert(&map, "4", ft_strdup("d"));
	if (compare_maps(&map, "1 a|2 b|3 c|4 d"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_map(&map);

/* Case 04 ft_mapinsert with reindexing */

	ft_printf("{blue}Case 04 [ft_mapinsert with reindexing] -------------{reset}\n\n");
	map = ft_mapinit(4, NULL, test_valuedel);
	create_map(&map, "1 a|2 b|3 c");
	ft_mapinsert(&map, "4", ft_strdup("d"));
	if (map->size > 4 && compare_maps(&map, "1 a|2 b|3 c|4 d"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_map(&map);

/* Case 05 ft_mapdelkey */

	ft_printf("{blue}Case 05 [ft_mapdelkey] -------------{reset}\n\n");
	map = ft_mapinit(4, NULL, test_valuedel);
	create_map(&map, "1 a|2 b|3 c");
	ft_mapdelkey(&map, "3");
	if (compare_maps(&map, "1 a|2 b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_map(&map);

/* Case 06 ft_mapdelkey with nonexistent key */

	ft_printf("{blue}Case 06 [ft_mapdelkey with nonexistent key] -------------{reset}\n\n");
	map = ft_mapinit(20, NULL, test_valuedel);
	create_map(&map, "1 a|2 b|3 c|4 f|5 gg|6 hggd|80 abcdft|gaga 15");
	ft_mapdelkey(&map, "nonexistent key");
	if (compare_maps(&map, "1 a|2 b|3 c|4 f|5 gg|6 hggd|80 abcdft|gaga 15"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_map(&map);

/* Case 07 ft_mapdelind */

	ft_printf("{blue}Case 07 [ft_mapdelind] -------------{reset}\n\n");
	map = ft_mapinit(20, NULL, test_valuedel);
	create_map(&map, "1 a|2 b|3 c|4 f|5 gg|6 hggd|80 abcdft|gaga 15");
	ft_mapdelind(&map, 2);
	if (compare_maps(&map, "1 a|2 b|3 c|4 f|5 gg|80 abcdft|gaga 15"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_map(&map);

/* Case 08 ft_mapdelind with nonexistent index */

	ft_printf("{blue}Case 08 [ft_mapdelind with nonexistent index] -------------{reset}\n\n");
	map = ft_mapinit(20, NULL, test_valuedel);
	create_map(&map, "1 a|2 b|3 c|4 f|5 gg|6 hggd|80 abcdft|gaga 15");
	ft_mapdelind(&map, 100);
	if (compare_maps(&map, "1 a|2 b|3 c|4 f|5 gg|6 hggd|80 abcdft|gaga 15"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_map(&map);

/* Case 09 ft_ismapitem */

	ft_printf("{blue}Case 09 [ft_ismapitem] -------------{reset}\n\n");
	map = ft_mapinit(20, NULL, test_valuedel);
	create_map(&map, "1 a|2 b|3 c|4 f|5 gg|6 hggd|80 abcdft|gaga 15");
	if (ft_ismapitem(map, "1") && ft_ismapitem(map, "gaga") && ft_ismapitem(map, "80"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_map(&map);

/* Case 10 ft_ismapitem */

	ft_printf("{blue}Case 10 [ft_ismapitem] -------------{reset}\n\n");
	map = ft_mapinit(20, NULL, test_valuedel);
	create_map(&map, "1 a|2 b|3 c|4 f|5 gg|6 hggd|80 abcdft|gaga 15");
	if (!ft_ismapitem(map, "hgaf") && !ft_ismapitem(map, "a fa fa ") && !ft_ismapitem(map, "afkafkakf"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_map(&map);

/* Case 11 ft_mapvalue */

	ft_printf("{blue}Case 11 [ft_mapvalue] -------------{reset}\n\n");
	map = ft_mapinit(20, NULL, test_valuedel);
	create_map(&map, "1 a|2 b|3 c|4 f|5 gg|6 hggd|80 abcdft|gaga 15");
	if (ft_strequ(ft_mapvalue(map, "6"), "hggd"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_map(&map);

/* Case 12 ft_mapvalue */

	ft_printf("{blue}Case 12 [ft_mapvalue] -------------{reset}\n\n");
	map = ft_mapinit(20, NULL, test_valuedel);
	create_map(&map, "1 a|2 b|3 c|4 f|5 gg|6 hggd|80 abcdft|gaga 15");
	if (ft_mapvalue(map, "6afaf") == NULL)
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_map(&map);
}
