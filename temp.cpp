#include <stdio.h>
#include <string.h>
int main()
{
    static int num[3] = {[0] = 5, [2] = 7};
    printf("%d", num[1]);
    return 0;
}
