#include <stdio.h>

void threeSum(int nums[], int numsSize, int target) {
    for (int i = 0; i < numsSize - 2; i++) {
        for (int j = i + 1; j < numsSize - 1; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                if (nums[i] + nums[j] + nums[k] == target) {
                    printf("%d %d %d\n", nums[i], nums[j], nums[k]);
                }
            }
        }
    }
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;

    threeSum(nums, numsSize, target);

    return 0;
}
