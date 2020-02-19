void swap(int *nums, int a, int b){
    int tmp;
    tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

void moveZeroes(int* nums, int numsSize){
    int slow = 0, fast = 0;
    while(fast < numsSize){
        if(nums[slow] == 0 && nums[fast] == 0){
            fast++;
        }else if(nums[slow] == 0 && nums[fast] != 0){
            swap(nums, slow, fast);
            slow++, fast++;
        }else if(nums[slow] != 0 && nums[fast] ==0){
            slow++, fast++;
        }else{
            if(slow < fast) slow++;
            else slow++, fast++;
        }
    }
}

