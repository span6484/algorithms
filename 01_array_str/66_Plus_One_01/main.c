/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i = 0,flag = 1, tmpbox = 0;
    int* tmp = (int*)malloc(sizeof(int) * (digitsSize + 1));
    for(i = 0; i < digitsSize; i++){
        tmp[i] = digits[digitsSize-i-1];
    }
    tmp[digitsSize] = 0;
    for(i = 0; i< digitsSize+1; i++){
        if(tmp[i] + flag > 9){
            tmp[i] = tmp[i] + flag - 10;
            flag = 1;
        }else{
            tmp[i] = tmp[i] + flag;
            flag = 0;
        }
    }
    if(tmp[digitsSize] == 0){
        int* res = (int*)malloc(sizeof(int) * (digitsSize));
        for(i = 0; i < digitsSize; i++){
            res[i] = tmp[digitsSize-i-1];
        }
        *returnSize = digitsSize;
        return res;
    }else{
        int* res = (int*)malloc(sizeof(int) * (digitsSize + 1));
        for(i = 0; i < digitsSize + 1; i++){
            res[i] = tmp[digitsSize - i];
        }
        *returnSize = digitsSize + 1;
        return res;
    }

}

