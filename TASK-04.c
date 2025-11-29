#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int n, extra, i;
    float total = 0;

    printf("Enter number of days: ");
    scanf("%d", &n);

    float *sales = (float*)malloc(n * sizeof(float));
    if (sales == NULL) 
    {
    printf("\n Memory Allocation Failed!");
    return 1;
    }
    printf("Enter sales for %d days:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &sales[i]);
        total += sales[i];
    }

    printf("\nTotal Sales = %.2f", total);

    printf("\nEnter number of additional days: ");
    scanf("%d", &extra);

    sales = (float*)realloc(sales, (n + extra) * sizeof(float));
    if (sales==NULL)
    {
       printf("\n Memory Allocation Failed!");
    return 1; 
    }

    printf("Enter sales for the new %d days:\n", extra);
    for (i = n; i < n + extra; i++) {
        scanf("%f", &sales[i]);
        total+=sales[i];
    }
    printf("\nUpdated Total Sales = %.2f\n", total);

    free(sales);
    return 0;
}
