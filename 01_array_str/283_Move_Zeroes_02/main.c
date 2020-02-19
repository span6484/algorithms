void moveZeroes(int* nums, int numsSize){
    int slow = 0, fast = 0;
    while(fast < numsSize){
        if(nums[fast] != 0){
            nums[slow++] = nums[fast++]; 
        }else{
            fast++;
        }
    }
    while(slow < numsSize){
        nums[slow++] = 0;
    }
}
