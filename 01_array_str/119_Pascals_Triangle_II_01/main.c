int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    int* res = malloc(sizeof(int) * (rowIndex + 1));
    long cur = 1;
    res[0] = 1;
    for(int i = 1; i <= rowIndex; i++){
        cur = (long)res[i-1] * (rowIndex-i+1) / i;
        res[i] = (int)cur;
    }
    return res;
}


