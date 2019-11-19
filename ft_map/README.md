# ft_map

Библиотека для работы c хеш-таблицами

#### Структура таблицы:
```
typedef struct           s_map
{
	t_list           **array;		// массив односвязных списков
	size_t           size;			// размер таблицы
	void		 *valuedel_func;	// указатель на функцию для удаления значения
}			 t_map;
```

##### Структура элемента массива `array`:
```
typedef struct           s_htab
{
	char             *key;
	void             *value;
}                        t_htab;
```

Решение коллизий реализовано с помощью односвязных списков (при одном и том же хеше у разных ключей, элемент добавляется в следующий элемент списка по тому же индексу массива array).

Поле `valuedel_func` необходимо, чтобы в качестве значения хеш-таблицы можно было использовать любые типы данных.

#### Функции:

* `t_map                  *ft_mapinit(size_t mapsize, void *valuedel_func);`
  
  Инициализация структуры, выделение памяти

* `void                   ft_mapinsert(t_map **map, const char *key, void *value);`
  
  Добавление значения по указаному ключу
  
* `int                    ft_ismapitem(t_map *map, const char *key);`
  
  Проверка существования ключа

* `const void             *ft_mapvalue(t_map *map, const char *key);`
  
  Возвращает константный указатель на значение хеш-таблицы по данному ключу

* `void                   ft_mapdel(t_map **map);`
  
  Полное освобождение памяти

* `void                   ft_mapdelind(t_map **map, size_t index);`
  
  Удаление значения по индексу в массиве списков

* `void                   ft_mapdelkey(t_map **map, const char *key);`
  
  Удаление значения по ключу

* `void                   ft_putmap(t_map *map, void (*printvalue)(void *));`
  
  Вывод таблицы на экран
