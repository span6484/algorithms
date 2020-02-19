int removeDuplicates(int* nums, int numsSize){
    int i = 0, slow = 0, fast = 0;
    if(!nums || !numsSize) return 0; 
    while(fast < numsSize){
        if(nums[fast] == nums[slow]){
            fast++;
        }else{
            nums[++slow] = nums[fast++];
        }
    }
    return slow+1;
}

