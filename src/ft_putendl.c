/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:51:48 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/16 15:31:44 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(char const *s)
{
	if (!s)
		return ;
	ft_putstr(s);
	write(1, "\n", 1);
}
