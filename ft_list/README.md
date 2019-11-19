# ft_list

Библиотека для работы с односвязными списками.

#### Структура:
```
typedef struct                  s_list
{
	void                    *content;         // содержимое элемента списка
	size_t                  content_size;     // количество памяти, необходимое для хранения content (sizeof(<content>))
	struct s_list           *next;            // указатель на следующий элемент
}                               t_list;
```

#### Функции:

* `t_list                       *ft_lstnew(void *content, size_t content_size);`
  
  Создание нового элемента списка

* `void                         ft_lstadd(t_list **alst, t_list *new);`
  
  Добавление элемента в начало списка `alst`
  
* `void                         ft_lstaddhere(t_list **alst, t_list *new, size_t position);`
  
  Добавление элемента в список в указаное место

* `void                         ft_lstpushback(t_list **alst, t_list *new);`
  
  Добавление элемента в конец списка

* `void                         ft_lstdel(t_list **alst, void (*del)(void *, size_t));`
  
  Освобождение памяти, удаление всего списка

* `void                         ft_lstdelone(t_list **alst, void (*del)(void *, size_t));`
  
  Освобождение памяти, удаление одного элемента

* `void                         ft_lstdelthis(t_list **alst, size_t lstnum, void (*del)(void *, size_t));`
  
  Удаление элемента по номеру

* `void                         ft_lstdeltail(t_list **alst, void (*del)(void *, size_t));`
  
  Удаление последнего элемента

* `void                         ft_lstiter(t_list *lst, void (*f)(t_list *elem));`
  
  Применение функции к каждому элементу

* `t_list                       *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));`
  
  Возвращает указатель на новый список (копию `lst`), к каждому элементу которого применена функция `f`

* `void                         ft_lstprint(t_list *alst, void (*print)(void *));`
  
  Вывод на экран

* `size_t                       ft_lstsize(t_list *alst);`
  
  Подсчет количества элементов в списке
