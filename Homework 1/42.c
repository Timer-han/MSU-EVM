#include <stdio.h>

int main() {
    FILE *in, *out;
    int m, n, k = 1, mx = 0;
    char a[128] = "";
    printf("\n[+] Please, write the name of the input file.\n");
    scanf("%s", a);
    in = fopen(a, "r");
    if (in == NULL) {
        printf("[+] Can't open %s. Error\n", a);
        return -1;
    }
    if (fscanf(in, "%d", &m) != 1) {
        printf("[+] Too little data in the files.\n");
        return -2;
    }
    while (fscanf(in, "%d", &n) == 1) {
        if (n >= m) {
            k++;
        } else {
            mx = k > mx ? k : mx;
            k = 1;
        }
        m = n;
    }
    mx = k > mx ? k : mx;
    printf("[+] length = %d\n", mx);

    return 0;
}
