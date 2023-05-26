# Хорошее оформление кода

``` c
int main(void) {
    char *c;
    c = (char*) malloc(n * sizeof(char));
    c[0] = 0;

    //Your program

    free(c);
}
```
Заполнение указателя нулями в количестве n штук
`for (int i = 0; i < n; i++) s[i] = 0;` <=> `memset(s, 0, n);`
Но `memset` работает быстрее
А также можно вместо `malloc` использовать `calloc`, он выделяет память и заполняет нулями.

# Измерение времени

``` c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

double time_now(void);
double time_now(void){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv.sec + tv.tv_usec/1000000.0;
    
}

int solve_full_read(const char *filename){
    FILE *f = fopen(filename, "r");
    if (f == NULL){
        return -1;
    }
    fseek(f, 0, SEEK_END);
    len = (int)ftell(f);
    
    fclose(f);
}

int main(void){
    printf("USING FULL READ: %d\n", solve_full_read("sheakspear.txt"));
    return 0;
}

```
