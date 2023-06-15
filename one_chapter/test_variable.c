#include <stdio.h>

int g_t;
static int s_t;
int main() {
    int t1;
    static int t2;
    int t3;
    int t4;
    printf("%d\n",g_t);
    printf("%d\n",s_t);
    printf("%d\n",t1);
    printf("%d\n",t2);
    printf("%d\n",t3);
    printf("%d\n",t4);


    return 0;
}