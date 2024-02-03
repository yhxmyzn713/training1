#include <stdio.h>
#include <string.h>

int main() {
    int result = 6;

    printf("result = %d\n", result);

    int zxh[3] = {1, 2, 3};
    //memset(zxh, 0, 3 * sizeof(int));

    printf("%d %d %d\n", zxh[0], zxh[1], zxh[2]);


    int *p = &zxh[1];

    printf("%d %d\n", p[0], zxh[0]); 
}
