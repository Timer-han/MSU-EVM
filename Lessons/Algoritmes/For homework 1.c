#include <stdio.h>

int solve_task_123(const char  * file_name){
    FILE *f;
    int a, b, c;
    f = fopen(file_name, "r");
    if (!f) {
        return -1;
    }
    while(){
        //code
    }
    if (!feof(f)){
        fclose(f);
        return -2;
    }
    fclose(f);
    return x;
}
int main() {
    printf("Result: %d\n", solve_task_123("data.txt"));
}
