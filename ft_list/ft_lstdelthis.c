/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelthis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:04:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/19 13:45:45 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Deletes a list item by its number
**
** @param 		lstnum			list number to delete
** @param		del
** @return		N/A
*/

void				ft_lstdelthis(t_list **alst, size_t lstnum, \
											void (*del)(void *, size_t))
{
	t_list			*tmp;

	while (*alst != NULL && lstnum)
	{
		alst = &(*alst)->next;
		lstnum--;
	}
	if (lstnum == 0 && *alst != NULL)
	{
		tmp = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = tmp;
	}
}
