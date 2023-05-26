# Работа с каталогами
| Стандарт | Система |
| -------- | ------- |
|          | Unix    |
|          | Windows |

## Чтение файла
``` c
FILE * f = fopen(...);
while fgets();
fclose(f);
```
## Чтение каталога
``` c
DIR * d = opendir("your_direct");
if (d == NULL){
	return 0;
}
closedir(d);
```
Что указывать в `OPENDIR()` ?
-Абсолютный путь
"/usr/localhost/.../dir"
-Относительный путь
"./b/cdir"

Как получить текущую папку?
>\> pwd 

Вспомним структуры:
``` c
#include <dirent.h>

struct f{
	int x;
	char name[200];
};
struct f a, *b;
a.x;
(*b).x <=> b[0].x //как получить x, когда структура задана через указатель
b -> x //но это удобнее
```

``` c
DIR * d = opendir("your_direct");
struct dirent * item;
if (d == NULL){
	return 0;
}
while (item = readdir(d)){
	// readdir читает следующую запись
	item -> d_name; // получаем имя файла
	item -> d_type; // тип файла
	if (item -> d_name[0] == "."){
		continue;
		// пропускаем все ненужные каталоги по типу "/.", "/..", "/.config"
	}
	if (item -> d_type == DT_DIR){
		// Это папка, работаем с ней
		printf("DIR: %s", item -> d_name);
	}
	if (item -> d_type == DT_REG){
		// Это обычный файл, работаем с ней
		printf("FILE: %s", item -> d_name);
	}
	//
	//
}
closedir(d);
```

## Как обойти всё дерево? Рекурсия!
``` c
	void printd(char *path){
	d = opendir(...);
	while(i = readdir(d)){
		if (i -> d_type == DT_DIR){
			printd(i -> d_name);
		}
	}
	closedir(d);
}
```

# FTW
``` c
// тут можно использовать глобальный массив
void f(char *s /*имя файла*/, struct stat *st /*похожая на dirent*/){
	//код обработки файлов
}
ftw("/usr", &f, 20);
```