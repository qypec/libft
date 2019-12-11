#include "unit_test.h"

static t_list			*listnew(void *content, size_t content_size)
{
	t_list				*list;

	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->content = content;
	if (list->content != NULL)
		list->content_size = content_size;
	else
		list->content_size = 0;
	list->next = NULL;
	return (list);
}

static void				listpushback(t_list **alst, t_list *new)
{
	if (new == NULL)
		return ;
 	while (*alst != NULL)
    	alst = &(*alst)->next;
    *alst = new;
}

t_list					*create_list(const char *str_items)
{
	t_list				*list;
	char				**items;
	size_t				i;

	if (str_items[0] == '\0')
		return (NULL);
	items = ft_strsplit(str_items, ' ');
	list = NULL;
	i = 0;
	while (items[i] != NULL)
		listpushback(&list, listnew(ft_strdup(items[i++]), sizeof(char *)));
	ft_matrdel(&items);
	return (list);
}

static void				delete_head_item(t_list **alst, void (*del)(void *, size_t))
{
	t_list				*tmp;

	if (*alst == NULL)
		return ;
	tmp = (*alst)->next;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = tmp;
}

void					delete_list(t_list **alst, void (*del)(void *, size_t))
{
	t_list				*tmp;
	
	while (*alst != NULL)
		delete_head_item(alst, del);
}