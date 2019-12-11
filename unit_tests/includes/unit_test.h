#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include "../../includes/libft.h"

void					del_strcontent(void *content, size_t content_size);

t_list					*create_list(const char *str_items);
void					delete_list(t_list **alst, void (*del)(void *, size_t));

int						compare_this(t_list *actual, const char *str_expected);

void					test_ft_list(void);

void					test_ft_map(void);

void					delete_map(t_map **map);

#endif