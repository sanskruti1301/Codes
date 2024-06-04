#include <stdio.h>
#include <stdlib.h>

int pair(int n, int a[n])
{
    int i,j=0;
    int count=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
                count++;
        }
    }
   return count;
}



int main()
{   int i,result=0,n;
printf("\nEnter the size \n");
scanf("%d",&n);
int a[n];
    printf("\nEnter the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    result= pair(n,a);
    printf("\n good pairs are: %d\n",result);

    return 0;
}
