#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char str[80];
    printf("Vvedite stroku: ");
    scanf("%s", str);

    for (i = 0; i < 80; i++)
    {
        if (str[i] == 'a')
            str[i] = 'A';
        else if (str[i] == 'b')
            str[i] = 'B';
    }

    printf(str);

    return 0;
}
