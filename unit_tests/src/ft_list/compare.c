/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:44:42 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/17 01:44:50 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

int						compare_this(t_list *actual, const char *str_expected)
{
	t_list				*expected;
	t_list				*tmp;

	expected = create_list(str_expected);
	tmp = expected;
	while (actual != NULL)
	{
		if (!ft_strequ((const char *)(actual->content), \
				(const char *)(expected->content)))
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
