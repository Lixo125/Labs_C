#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char str[80];
    printf("Vvedite stroku: ");
    scanf("%s", str);

    for (i = 0; i < 80; i++)
        str[i] = toupper(str[i]);
    printf(str);

    return 0;
}
