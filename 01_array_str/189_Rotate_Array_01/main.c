
void reverse(int* nums, int start, int end){
    int i = start, j = end, tmp = 0;
    while(i < j){
        tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
        i++, j--;
    }
}

void rotate(int* nums, int numsSize, int k){
    int mov = k % numsSize;
    reverse(nums, 0, numsSize - mov -1);
    reverse(nums, numsSize - mov, numsSize - 1);
    reverse(nums,0, numsSize -1);
}


