#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<fcntl.h>

int ch, inWord = 0, wordsCount = 0, y = 0, x = 0;
char arr[2000][25];
main()
{
    FILE* file = fopen("C:/proga/file.txt", "r");
    if (file == NULL)
    {
        printf("Error read file!");
    }
    else
    {
        while ((ch = fgetc(file)) != EOF)
        {
            if (isspace(ch) || ispunct(ch) || isdigit(ch))
            {
                if (inWord)
                {
                    wordsCount++;
                    inWord = 0;
                    y++;
                    x = 0;
                }
            }
            else
            {
                inWord = 1;
                arr[y][x] = ch;
                x++;
            }
        }

        wordsCount += inWord;
        printf("Count word: %d\n", wordsCount);
        
        int i;
        for ( i = 0; i < wordsCount; i++)
        {
            printf("%4d) %s\n", (i + 1), arr[i]);
        }
    }
}
