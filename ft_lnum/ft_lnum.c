/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:35:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/06/13 16:02:45 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lnum.h"
# include <stdio.h>

char					*formula_1(t_lnum lnum)
{
	
}

t_lnum					get_source(double num)
{
	unsigned long long	*ptr;
	t_lnum				lnum;

	ptr = (unsigned long long *)&num;
	lnum.sign = *ptr >> 63;
	lnum.mantissa = *ptr;
	lnum.mantissa <<= 12;
	lnum.mantissa >>= 12;
	lnum.expon = (*ptr >> 52) - 1023;
	return (lnum);
}

char					*ft_lnum_double(double num)
{
	t_lnum				lnum;

	lnum = get_source(num);
	if (DOUBLE_POW_CONST - lnum.expon > 0)
		return (formula_1(lnum));
	// else
	// 	return (formula_2(lnum));
	// printf("itoa = %s\n", ft_itoa(lnum.mantissa));
	// printf("%lld\n", lnum.mantissa);
	// printf("%d\n", lnum.expon);
	return (NULL);
}

int						main()
{
	printf("%s\n", ft_lnum_double(1231000.12222122441245174646114));
}