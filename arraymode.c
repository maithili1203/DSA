#include<stdio.h>
main()
{
  int arr[100],n,i;
  printf("enter the value of n");
  scanf("%d",&n);
  printf("enter array elements");
  for(i=0;i<n;i++)
  {
  scanf("%d",&arr[i]);
  }
  printf("array elements are");
  for(i=0;i<n;i++)
  {
   printf("%d\n",arr[i]);

  }
  for(i=0;i<n;i++)
  {
      int m=0,j;
      for(j=0;j<n;j++)
      {
          if(arr[i]==arr[j])
          {
              m++;
          }
      }
      printf("%d is repeated %d times\n",arr[i],m);
  }

}
