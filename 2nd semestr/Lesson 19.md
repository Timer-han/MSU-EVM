# Define как функция

``` c
#define s(x) x + 1

y = s(3) + 8; //Вместо Х подставляет 3
```

``` c
double sgn(double x){
	return x > 0? 1 : -1
}
// OR
#define SGN(x) (x > 0 ? 1 : -1)
```
Второй вариант лучше, так как он в РАЗЫ быстрее, а так же он работает для всех типов данных.
``` c
int sgn(double x){
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}
// OR
#define SGN(x) x > 0 ? 1 : (x < 0? -1 : 0)

int main(void) {
	x = 1;
	y = -2 + sgn(x); // -1
	y = -2 + SGN(x); // -3
}
```

``` c
int sgn(double x){
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}
// OR
#define SGN(x) (x > 0 ? 1 : (x < 0? -1 : 0))

int main(void) {
	x = 1;
	y = sgn(1 && -1); 
	y = SGN(1 && -1); // Косячит
}
```

``` c
int sgn(double x){
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}
// OR
#define SGN(x) ((x) > 0 ? 1 : ((x) < 0? -1 : 0))

int main(void) {
	x = 1;
	y = sgn(--x); // x = 0, y = 0
	y = SGN(--x); // Косячит, y = -1 и x = -1
}
```