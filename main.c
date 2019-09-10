#include "libft.h"

# define TYPE (t_bla *)
# define CONTENT(head) (TYPE(head->content))

typedef struct		s_bla
{
	char 			*str;
	int				h;
}					t_bla;

void				strdellst(t_list *head)
{
	ft_strdel((char **)&(head->content));
	head->delfunc = NULL;
	free(head);
	head = NULL;
}

void				delbla(t_list *head)
{
	ft_strdel(&(((t_bla *)(head->content))->str));
	free(head->content);
	head->content = NULL;
	head->delfunc = NULL;
	free(head);
	head = NULL;
}

int					main(void)
{
	t_list			*head;
	t_bla			*bla;

	// head = ft_lstnew((void *)ft_strdup("haha"), &strdellst);
	// ft_lstdel(&head);
	bla = (t_bla *)malloc(sizeof(t_bla));
	bla->str = ft_strdup("haha");
	bla->h = 1;
	head = ft_lstnew((void *)bla, &delbla);
	ft_printf("%s", CONTENT(head)->str);
	ft_lstdel(&head);
}