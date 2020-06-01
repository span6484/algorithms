int findMaxConsecutiveOnes(int* nums, int numsSize){
    int max = 0, i = 0, j = -1;
    for(i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            max = max > (i-j-1)? max:(i-j-1);
            j = i;
        }
    }
    max = max > (numsSize-j-1)? max:(numsSize-j-1);
    return max;
}
