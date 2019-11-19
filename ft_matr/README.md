# ft_matr

Библиотека для работы с массивами строк

#### Функции:

* `char                 **ft_matrnew(const char *first_str, ...);`
  
  Выделение памяти под массив строк (функция принимает переменное количество строк)

* `char                 **ft_matrsnew(size_t matr_size, size_t line_size);`
  
  Выделение памяти под массив строк (функция принимает размер массива и размер строк)
  
* `char                 **ft_matrmemalloc(size_t size);`
  
  Выделение памяти и зануление строк

* `char                 **ft_matrdup(const char **matr);`
  
  Возвращает указатель на новый массив строк (копия)

* `void                 ft_strswap(char **matr, int first, int second);`
  
  Меняет местами строки в массиве строк

* `void                 *ft_matrdel(char ***ret);`
  
  Удаление, освобождение памяти

* `size_t               ft_matrlen(const char **matr);`
  
  Подсчет строк
