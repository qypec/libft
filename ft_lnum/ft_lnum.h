/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnum.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:32:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/13 15:57:15 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTIME_H
# define FT_CTIME_H

# include "../includes/libft.h"

# define	DOUBLE_POW_CONST	52

typedef struct					s_lnum
{
	short						sign;
	long long					mantissa;
	short						expon;
}								t_lnum;

#endif