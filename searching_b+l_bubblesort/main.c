#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int n){
for(int i=0;i<n;i++){
    printf("%d \t",arr[i]);
}
}
void bubbleSort(int *arr, int n){
int isSorted=0,temp=0;
for(int i=0;i<n-1;i++){
    isSorted=1;
    for(int j=0;j<n-1-i;j++){
        if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            isSorted=0;
        }
    }
    if(isSorted){
        return;
    }
}
}

int linearSearch(int arr[], int n, int e){
for(int i=0;i<n;i++){
    if(arr[i]==e){
        return i;
    }
}
return -1;
}
int binarySearch(int arr[], int n, int e){
int l=0,h=n-1,m=0;

while(l<=h){
        m = l + (h - l) / 2;
    if(arr[m]==e){
        return m;
    }
    else if(arr[m]>e){
        h= m-1;
    }
    else{
        l= m+1;
    }
}
return -1;

}

int main()
{   int n;
    printf("enter size of array \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter integers of array \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int e;
    printf("Enter element to search \n");
    scanf("%d",&e);
    int Lindex= linearSearch(arr,n,e);
    if(Lindex!=-1){
    printf("%d in the array is present at %d position by linear search \n", e,Lindex+1);}
    printf("\n Array before sorting \n");
    printArray(arr,n);
    bubbleSort(arr,n);
    printf("\n Array after sorting \n");
    printArray(arr,n);
    int Bindex= binarySearch(arr,n,e);
    if(Bindex!=-1){
    printf("\n %d in the array is present at %d position by binary search \n", e,Bindex+1);}
    else{printf("\n Element is not present in the array \n");}
    return 0;
}
