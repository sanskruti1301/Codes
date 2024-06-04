#include <stdio.h>
#include <stdlib.h>

int main()
{   int n,i, max=0, min,j;
    printf("Enter no of elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elememts of array \n");
    for( i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     max = min = arr[0];
    for(i=0;i<n;i++){

        if(arr[i]>max){
            max=arr[i];
        }

    }
    printf("%d \n", max);
    for(i=0;i<n;i++){

        if(arr[i]<min){
            min=arr[i];
        }

    }
    printf("%d \n", min);
    return 0;
}
