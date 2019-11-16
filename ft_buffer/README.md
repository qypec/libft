# ft_buffer

Библиотека для работы со строками неопределенного размера.

#### Структура:
```
typedef struct      s_buff
{
  char              *line;            // строка
  size_t            size;             // ее размер
  size_t            totalsize;        // размер, на который выделена память
  size_t            additional_size;  // количество памяти, которая будет добавлена при следующем переполнении буфера
}                   t_buff;
```

#### Функции:

* `t_buff					*ft_buffinit(size_t size);`
  
  Инициализация структуры, выделение памяти

* `void					ft_buffaddsymb(t_buff *buff, char c);`
  
  Добавление символа
  
* `void					ft_buffadd(t_buff *buff, const char *str);`
  
  Добавление строки

* `void					ft_buffladd(t_buff *buff, const char *str, size_t len);`
  
  Добавление строки определенного размера

* `void					ft_buffdel(t_buff **buff);`
  
  Освобождение памяти, удаление
