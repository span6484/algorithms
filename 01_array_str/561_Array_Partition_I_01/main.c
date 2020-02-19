int comp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

int arrayPairSum(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),comp);
    int i = 0, res = 0;
    while(i < numsSize){
        res += nums[i];
        i += 2;
    }
    return res;
}


