#include <stdio.h>
#include <stdlib.h>

int RemoveD( int* nums, int size)
{
    if(size==0)
    {
        return 0;
    }
    int i=0;
    for(int j=1;j<size;j++)
    {
        if(nums[i]!nums[j])
        {
            i++;
            nums[i]=nums[j];
        }
    }
    return i+1;

}
