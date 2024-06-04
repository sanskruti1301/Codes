#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{   int i,j,n,r[10];
    printf("\nEnter the integer\n");
    scanf("%d",&n);
    for(i=0;i<10;i++)
    {  if(n%10!=0){
       r[i]=n%10; }
       n= n/10;
    }
    printf("reversed integer\n");
    for(i=0;i<10;i++)
    {
        printf("\n %d\n",r[i]);
    }
    return 0;
}
