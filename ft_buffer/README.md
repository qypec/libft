# ft_buffer

Библиотека для работы со строками неопределенного размера.

Структура:
```
typedef struct      s_buff
{
  char              *line;            // строка
  size_t            size;             // ее размер
  size_t            totalsize;        // размер, на который выделена память
  size_t            additional_size;  // количество памяти, которая будет добавлена при следующем переполнении буфера
}                   t_buff;
```

Функции:

* `t_buff					*ft_buffinit(int size);`

* `void					ft_buffaddsymb(t_buff *buff, char c);`
  
* `void					ft_buffadd(t_buff *buff, const char *str);`

* `void					ft_buffladd(t_buff *buff, const char *str, int len);`

* `void					ft_buffdel(t_buff **buff);`
