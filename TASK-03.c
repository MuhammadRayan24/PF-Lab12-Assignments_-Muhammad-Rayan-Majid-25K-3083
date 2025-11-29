#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare_ignore_case(const char *a, const char *b) 
{
    while (*a && *b) 
    {
        char c1 = (*a >= 'A' && *a <= 'Z') ? *a + 32 : *a;
        char c2 = (*b >= 'A' && *b <= 'Z') ? *b + 32 : *b;
        if (c1 != c2)
            return c1 - c2;
        a++;
        b++;
    }
    return *a - *b;
}
int main() 
{
    int n, i;
    int positions[100];
    int totalSize = 0;

    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar();

    char *buffer = malloc(1000);
    if (buffer == NULL)
        return 1;

    for (i = 0; i < n; i++) 
    {
        char str[200];
        printf("Enter string %d: ", i + 1);
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        positions[i] = totalSize;
        strcpy(&buffer[totalSize], str);
        totalSize += strlen(str) + 1;
    }

    for (i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) {
            char *s1 = &buffer[positions[i]];
            char *s2 = &buffer[positions[j]];
            if (compare_ignore_case(s1, s2) > 0) 
            {
                int temp = positions[i];
                positions[i] = positions[j];
                positions[j] = temp;
            }
        }
    }

    printf("\nSorted Strings:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", &buffer[positions[i]]);

    free(buffer);
    return 0;
}
