#include <stdio.h>

int main() {
    FILE *in;
    int k, sm, p = 0, x, y, z;
    k = 1; sm = 0;
    in = fopen("logs.txt", "r");
    if (in == NULL){
        printf("\n[+] File not opened. Error\n");
        return -1;
    }
    while (fscanf(in, "%d", &x) == 1){
        if (x == 111){
            break;
        }
    }
    while (fscanf(in, "%d", &x) == 1){
        if (x % 2 == 1){
            break;
        }
    }
    if (fscanf(in, "%d%d", &x, &y) == 2){
        if (x > y && (x % 10 == 8 || x % 10 == 7)){
            sm += x;
        } else if(x == y && (y % 10 == 8 || y % 10 == 7)){
            p += y * 2;
            x = -2139999999;
        } else if (y > x && (y % 10 == 8 || y % 10 == 7)){
            p += y;
        }
    }
    while (fscanf(in, "%d", &z) == 1){
        if (z == y && (z % 10 == 8 || z % 10 == 7)){
            p += z;
        } else if (z > y ){
            if (z % 10 == 8 || z % 10 == 7)
            {
                p = z;
            }
            x = y;
            y = z;
        } else if (z < y){
            sm += p;
            p = 0;
            x = y;
            y = z;
        }
    }

    if (y > x){
        sm += p;
    }
    if (!feof(in)){
        printf("\n[+] I can't read numbers in this file. Sorry, my lord ._.\n");
        return -2;
    }
    printf("\n[+] Lord, your password is - [ %d ]\n", sm);

    return 0;
}
