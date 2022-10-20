#include <stdio.h>

int main() {
    FILE *in;
    int x, y, z;
    char a[128] = "";
    printf("\n[+] Please, write the name of the input file.\n");
    scanf("%s", a);
    in = fopen(a, "r");
    if (in == NULL){
        printf("[+] Can't open %s. Error\n", a);
        return -1;
    }
    if (fscanf(in, "%d%d", &x, &y) != 2){
        printf("[+] Too little data in the files.\n");
        return -2;
    }
    while (fscanf(in, "%d", &z) == 1){
        if (z * x != y * y){
            printf("[+] It isn't geometric progression.\n");
            return 0;
        }
        x = y;
        y = z;
    }
    if (!feof(in)){
        printf("[+] Error. Extra characters in the file.\n");
        return -3;
    }
    printf("[+] Yes, it is geometric progression!\n");

    return 0;
}
