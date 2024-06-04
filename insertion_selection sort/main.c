#include <stdio.h>
#include <stdlib.h>
void printarray(int *A, int n){
for(int i=0;i<n;i++){
    printf("%d \t",A[i]);
}
printf("\n");
}
void insertion(int * A, int n){
int key,i=0,j=0;
for(int i=1;i<=n;i++){
    key= A[i];
    j=i-1;
    while(j>=0 && A[j]>key){
        A[j+1]=A[j];
        j--;
    }
    A[j+1]=key;
}
}
void selection(int *A, int n){
int temp,i,j,id_min;
for(int i=0;i<n;i++){
    id_min=i;
    for(int j=i+1;j<n;j++){
        if(A[j]<A[id_min]){
            id_min=j;
        }
    }
    temp=A[i];
    A[i]= A[id_min];
    A[id_min]= temp;
}
}


int main()
{   int n,i;
    printf("Enter size \n");
    scanf("%d",&n);
    int a2[n];
    int a1[n];
    printf("Enter elements of array 1 \n");
    for(i=0;i<n;i++){
        scanf("%d",&a1[i]);
    }
    printf("Enter elements of array 2 \n");
    for(i=0;i<n;i++){
        scanf("%d",&a2[i]);
    }
    printf("\n Array 1 before sorting \n");
    printarray(a1,n);
    selection(a1,n);
    printf("\n Array 1 after sorting \n");
    printarray(a1,n);
    printf("\n Array 2 before sorting \n");
    printarray(a2,n);
    insertion(a2,n);
    printf("\n Array 2 after sorting \n");
    printarray(a2,n);

    return 0;
}
