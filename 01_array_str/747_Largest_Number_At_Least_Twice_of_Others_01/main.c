

int dominantIndex(int* nums, int numsSize){
    if(numsSize < 1)
        return -1;
    else if(numsSize == 1)
        return 0;
    int i = 0,max = nums[0],secMax = 0, flag = 0;
        
    for(i = 1; i < numsSize; i++){
        if(nums[i] > max){
            secMax = max;
            max = nums[i];
            flag = i;
        }else if(nums[i] < max && nums[i] > secMax){
            secMax = nums[i];
        }
    }
    if(max >= secMax*2){
        return flag;
    }else{
        return -1;
    }
}