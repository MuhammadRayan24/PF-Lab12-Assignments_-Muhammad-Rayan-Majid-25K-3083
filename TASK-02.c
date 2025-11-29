#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n , i;
  int*arr;

  printf("\n Enter The Total Number Of Integers To Enter: ");
  scanf("%d",&n);

  arr=(int*)calloc(n,sizeof(int));
  if(arr==NULL)
  {
    printf("\n Memory Allocation Failed!");
    return 1;
  }

  printf("\n Enter The Integers: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
   printf("\n Array Elements: ");
    for(i=0;i<n;i++)
  {
    printf("\n%d",arr[i]);
  }

  arr=(int*)realloc(arr,2*n*sizeof(int));
  if(arr==NULL)
  {
    printf("\n Memory Allocation Failed!");
    return 1;
  }

  printf("\n Add %d more integers to update array: ",n);
  for(i=n;i<2*n;i++)
  {
    scanf("%d",&arr[i]);
  }

  printf("\nUpdated array: ",n);
  for(i=0;i<2*n;i++)
  {
    printf("\n%d",arr[i]);
  }

  free(arr);
  return 0;
}