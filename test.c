#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

#define KERNEL_2D_MEMCPY 451

void print_mtrx(float inpt[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f ", inpt[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    float src[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    float dest[3][3] = {{0}};

    printf("original source matrix\n");
    print_mtrx(src);
    printf("original destination matrix\n");
    print_mtrx(dest);
    printf("-------kernel_2d_memcpy-------");
    syscall(KERNEL_2D_MEMCPY, src, dest, 3);
    printf("\n");
    printf("source matrix after syscall \n");
    print_mtrx(src);
    printf("original destination matrix\n");
    print_mtrx(dest);
    return 0;
}