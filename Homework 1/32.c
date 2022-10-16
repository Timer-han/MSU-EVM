#include <stdio.h>

int main() {
    FILE *in, *out;
    int m, n, k = 0, p;
    char a[128] = "";
    printf("\n[+] Please, write the name of the input file.\n");
    scanf("%s", a);
    in = fopen(a, "r");
    if (in == NULL){
        printf("[+] Can't open %s. Error\n", a);
        return -1;
    }
    if (fscanf(in, "%d%d", &m, &n) != 2){
        printf("[+] Too little data in the files.\n");
        return -2;
    }
    while (fscanf(in, "%d", &p) == 1){
        if (p + m == 2 * n) k++;
        m = n;
        n = p;
    }
    printf("[+] count = %d\n", k);

    return 0;
}
