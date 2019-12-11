#include "unit_test.h"

int						compare_this(t_list *actual, const char *str_expected)
{
	t_list				*expected;
	t_list				*tmp;

	expected = create_list(str_expected);
	tmp = expected;
	while (actual != NULL)
	{
		// ft_printf("\t\t\t%s\t%s\n", (char *)actual->content, (char *)expected->content);
		if (!ft_strequ((const char *)(actual->content), (const char *)(expected->content)))
			break ;
		if (expected->next == NULL)
			break ;
		actual = actual->next;
		expected = expected->next;
	}
	if (expected->next == NULL && actual->next == NULL)
	{
		delete_list(&tmp, del_strcontent);
		return (1);
	}
	delete_list(&tmp, del_strcontent);
	return (0);
}
