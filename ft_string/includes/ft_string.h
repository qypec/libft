/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:55:27 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/03 23:00:50 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# define SOME_ADDITIONAL_MEMORY 5

# include "../../includes/libft.h"

typedef struct		s_string
{
	char			*str;
	size_t			size;
	size_t			allocated_memory;
	size_t			additional_size;
	void			*content;
}					t_string;

t_string				*ft_stringnew(size_t size);

#endif