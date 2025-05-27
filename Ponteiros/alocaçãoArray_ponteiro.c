#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int a[3];
    int *pa;

    pa = (int*)malloc(10*sizeof(int));//alocação dianmica
    
    *(pa+0) = 10;
    *(pa+1) = 20;
     pa[2]  = 30;

     for(int i = 0; i < 3; i++){
        printf("%d\n",*(pa+i));
     }
    return 0;
}
