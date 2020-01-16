/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:50:27 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/17 01:50:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void					del_strcontent(void *content, size_t content_size)
{
	ft_strdel((char **)&content);
	content_size = 0;
}

void					test_ft_list(void)
{
	t_list				*list;
	int					size;

	ft_printf("{yellow}Check ft_list:{reset}\n\n");

/* Case 01 ft_lstadd */

	ft_printf("{blue}Case 01 [ft_lstadd] -------------{reset}\n\n");
	list = create_list("1 2 3 4 5 6 7");
	ft_lstadd(&list, ft_lstnew(ft_strdup("18"), sizeof(char *)));
	if (compare_this(list, "18 1 2 3 4 5 6 7"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 02 ft_lstadd with empty list */

	ft_printf("{blue}Case 02 [ft_lstadd with empty list] -------------{reset}\n\n");
	list = create_list("");
	ft_lstadd(&list, ft_lstnew(ft_strdup("18"), sizeof(char *)));
	if (compare_this(list, "18"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 03 ft_lstpushback */

	ft_printf("{blue}Case 03 [ft_lstpushback] -------------{reset}\n\n");
	list = create_list("1 2 3 4 5 6 7");
	ft_lstpushback(&list, ft_lstnew(ft_strdup("18"), sizeof(char *)));
	if (compare_this(list, "1 2 3 4 5 6 7 18"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 04 ft_lstpushback with empty list */

	ft_printf("{blue}Case 04 [ft_lstpushback with empty list] -------------{reset}\n\n");
	list = create_list("");
	ft_lstpushback(&list, ft_lstnew(ft_strdup("18"), sizeof(char *)));
	if (compare_this(list, "18"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 05 ft_lstaddhere in head */

	ft_printf("{blue}Case 05 [ft_lstaddhere in head] -------------{reset}\n\n");
	list = create_list("1 2 3 4 5");
	ft_lstaddhere(&list, ft_lstnew(ft_strdup("0"), sizeof(char *)), 0);
	if (compare_this(list, "0 1 2 3 4 5"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 06 ft_lstaddhere in head */

	ft_printf("{blue}Case 06 [ft_lstaddhere in tail] -------------{reset}\n\n");
	list = create_list("1 2 3 4 5");
	ft_lstaddhere(&list, ft_lstnew(ft_strdup("0"), sizeof(char *)), ft_lstsize(list));
	if (compare_this(list, "1 2 3 4 5 0"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 07 ft_lstaddhere */

	ft_printf("{blue}Case 07 [ft_lstaddhere] -------------{reset}\n\n");
	list = create_list("1 2 3 4 5");
	ft_lstaddhere(&list, ft_lstnew(ft_strdup("0"), sizeof(char *)), ft_lstsize(list) - 2);
	if (compare_this(list, "1 2 3 0 4 5"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 08 ft_lstdelthis head */

	ft_printf("{blue}Case 08 [ft_lstdelthis head] -------------{reset}\n\n");
	list = create_list("1 2 3 4 5");
	ft_lstdelthis(&list, 0, del_strcontent);
	if (compare_this(list, "2 3 4 5"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 09 ft_lstdelthis tail */

	ft_printf("{blue}Case 09 [ft_lstdelthis tail] -------------{reset}\n\n");
	list = create_list("1 2 3 4 5");
	ft_lstdelthis(&list, ft_lstsize(list) - 1, del_strcontent);
	if (compare_this(list, "1 2 3 4"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 10 ft_lstdelthis */

	ft_printf("{blue}Case 10 [ft_lstdelthis] -------------{reset}\n\n");
	list = create_list("1 2 3 4 5");
	ft_lstdelthis(&list, ft_lstsize(list) - 3, del_strcontent);
	if (compare_this(list, "1 2 4 5"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 11 ft_lstdelhead */

	ft_printf("{blue}Case 11 [ft_lstdelhead] -------------{reset}\n\n");
	list = create_list("1 2 3 4 5");
	ft_lstdelhead(&list, del_strcontent);
	if (compare_this(list, "2 3 4 5"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 12 ft_lstdeltail */

	ft_printf("{blue}Case 12 [ft_lstdeltail] -------------{reset}\n\n");
	list = create_list("1 2 3 4 5");
	ft_lstdeltail(&list, del_strcontent);
	if (compare_this(list, "1 2 3 4"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 13 ft_lstsize */

	size = 0;

	ft_printf("{blue}Case 13 [ft_lstsize] -------------{reset}\n\n");
	list = create_list("1 2 3 4 5");
	size = ft_lstsize(list);
	if (size == 5)
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);

/* Case 14 ft_lstsize with empty list*/

	size = 0;

	ft_printf("{blue}Case 14 [ft_lstsize with empty list] -------------{reset}\n\n");
	list = create_list("");
	size = ft_lstsize(list);
	if (size == 0)
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	delete_list(&list, del_strcontent);
}
