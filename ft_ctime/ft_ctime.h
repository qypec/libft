/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctime.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:34:50 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/03 22:48:26 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTIME_H
# define FT_CTIME_H

# include "../includes/libft.h"
# include <time.h>
# include <stdio.h> // no

# define WEEKDAY_OF_JANUARY_1ST_1970 4 /* Thursday */
# define DEL_CTIME_UNIX_SYS 10800 /* 3 hours */
# define START_YEAR	1970

typedef struct		s_cdate
{
	char			*weekday;
	int				weekday_n;
	char			*month;
	int				month_n;
	char			*day;
	int				day_n;
	char			*hour;
	int				hour_n;
	char			*min;
	int				min_n;
	char			*sec;
	int				sec_n;
	char			*year;
	int				year_n;
}					t_cdate;

/* ft_ctime */

char				*ft_ctime(const time_t *ttime);

/* -------- */

/* ft_uctime */

void				free_uctime(t_cdate *date);
t_cdate				*ft_uctime(const time_t *ttime);

/* --------- */

/* struct_to_str */

t_cdate				*struct_to_str(t_cdate *date);

/* ------------- */

/* get_temporary */

t_cdate				*getday_since1970(t_cdate *date, const time_t ttime, time_t *res);

/* ------------- */

/* getdata */

t_cdate				*getweekday(t_cdate *date, const time_t *res);
t_cdate				*gettime(t_cdate *date, const time_t *res);
t_cdate				*getyear(t_cdate *date, time_t ttime);
t_cdate				*getmonth(t_cdate *date);

/* ------- */

#endif