#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n,p;
    int i,j,k;
    printf("\n Enter The Number Of Rows for matrix A: ");
    scanf("%d",&m);
    printf("\n Enter Number Of Columns(matrix A)/Number Of Rows(matrix B): ");
    scanf("%d",&n);
    printf("\n Enter The Number Of Columns for matrix B: ");
    scanf("%d",&p);
    int (*A)[n]=malloc(m*sizeof(*A));
    int (*B)[p]=malloc(n*sizeof(*B));
    int (*C)[p]=malloc(m*sizeof(*C));
    if (A==NULL||B==NULL||C==NULL)
    {
        printf("\nMemory Allocation Failed! ");
        return 1;
    }
    
printf("\nEnter Elements Of Matrix A (%dx%d): ",m,n);
for(i=0;i<m;i++)
{
 for(j=0;j<n;j++) 
 {
    scanf("%d",&A[i][j]);
 }  
}
printf("\nEnter Elements Of Matrix B (%dx%d): ",n,p);
for(i=0;i<n;i++)
{
 for(j=0;j<p;j++) 
 {
    scanf("%d",&B[i][j]);
 }  
}

for(i=0;i<m;i++)
{
 for(j=0;j<p;j++) 
 {
    C[i][j]=0;
    for ( k = 0; k < n; k++)
    {
        C[i][j]+=A[i][k]*B[k][j];
    }
    
 }  
}

printf("\n Resultant Matrix:\n");
for(i=0;i<m;i++)
{
 for(j=0;j<p;j++) 
 {
   printf("%d ",C[i][j]);
 }  
 printf("\n");
}
free(A);
free(B);
free(C);
return 0;
}