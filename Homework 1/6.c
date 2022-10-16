#include <stdio.h>

int main() {
    FILE *in, *out;
    int m, n, km = 0, kn = 0, p;
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
        if (p == m) km++;
        if (p == n) kn++;
    }
    printf("[+] ");
    printf(km > kn ? "First" : kn > km ? "Second" : "equally");
    printf("\n");

    return 0;
}
