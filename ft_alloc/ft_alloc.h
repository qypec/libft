/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:13:41 by qypec             #+#    #+#             */
/*   Updated: 2019/06/12 10:58:07 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOC_H
# define FT_ALLOC_H

# include "../includes/libft.h"

void							*ft_realloc(void *ptr, size_t newsize);
void							*ft_memalloc(size_t size);
void							ft_memdel(void **ap);
void							ft_strdel(char **as);

#endif