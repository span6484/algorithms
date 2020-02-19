int pivotIndex(int* nums, int numsSize){
    int i =0,total = 0;
    if(numsSize < 1){
        return -1;
    }
    int left = 0;
    for(i=0; i<numsSize; i++){
        total += nums[i];
    }
    for(i=0; i<numsSize; i++){
        if(left*2 == total-nums[i]){
            return i;
        }
        left += nums[i];
    }
    return -1;
}


