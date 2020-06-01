/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i = 0, j = numbersSize - 1;
    *returnSize = 2;
    int* res = (int*)malloc(sizeof(int) * (*returnSize));
    while(i < j){
        if(numbers[i] + numbers[j] < target) i++;
        else if(numbers[i] + numbers[j] > target) j--;
        else{
            res[0] = i+1;
            res[1] = j+1;
            return res;
        }
    }
    return NULL;
}
