
int minSubArrayLen(int s, int* nums, int numsSize){
    int i = 0;
    int left = 0;
    int sum = 0;
    int res = INT_MAX;
    for(i = 0; i < numsSize; i++){
        sum += nums[i];
        while(sum >= s){
            res = res > (i - left + 1)? (i - left + 1):res;
            sum -= nums[left++];
        }
    }
    return res == INT_MAX? 0:res;
}


