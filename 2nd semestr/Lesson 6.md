# Нелинейные уравнения

f(x) = 0
Вся инфа в тетради

``` c
double f(double x){
    return x + 1;
}

double sin(double x){

}

double Newton(double x_0, double (*f) (double)  ){
    double x_n;
    x_n = x_0
    while(|x_n - x_p| < eps){
        x_p = x_n;
        x_n = x_p - f(x_p) / f'(x_p);
    return x_n;
}

int main() {
    x = Newton(0.5, f);
    x = Newton(0.5, sin);
    x = Newton(0.5, cos);

}
```
