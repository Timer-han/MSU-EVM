# Приведение строки в число
``` c
x = atoi(argv[1]);
y = atoi(argv[2]);
```

ИЛИ правильный метод
``` c
if (sscanf(argv[1], "%d", &x) != 1) return -1;
if (sscanf(argv[2], "%d", &y) != 1) retunn -1;
```

# Можно прямо в терминале задать ввод с консоли во время запуска программы
```
`echo <x> <y> | ./a.out`
| - перенаправляет вывод одного в ввод другого
`echo <x> <y> | ./a.out > b.txt`
> - записывает вывод в файл
`echo <x> <y> | ./a.out >> b.txt`
>> - он Дописывает файл
`echo <x> <y> | ./a.out > /dev/null`
Записывает в пустой файл
`cat /dev/random > /dev/null`
- Обогреватель
`echo <x> <y> | ./a.out | tee c.txt | tee b.txt`
tee - выводит и в файл и на экран
```