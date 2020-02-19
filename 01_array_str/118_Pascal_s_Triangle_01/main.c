int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** res = (int**)malloc(sizeof(int*) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    int i = 0, j = 1;
    for(i = 0; i < numRows; i++){
        res[i] = (int*)malloc(sizeof(int) * (i+1));
        (*returnColumnSizes)[i] = i+1;
        res[i][0] = res[i][i] = 1;
        j=1;
        while(j <= i/2){
            res[i][j] = res[i][i-j] = res[i-1][j-1] + res[i-1][j];
            j++;
        }
    }
    return res;
}
