/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:23:33 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/19 13:38:47 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds an item to the end of the list.
**
** @param 		alst	head of list
** @param 		new		new item
** @return		N/A
*/

void				ft_lstpushback(t_list **alst, t_list *new)
{
	if (new == NULL)
		return ;
 	while (*alst != NULL)
    	alst = &(*alst)->next;
    *alst = new;
}
