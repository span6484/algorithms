int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize == 0){   //好习惯，先判断
        *returnSize = 0;
        return NULL;
    }
    *returnSize = (*matrixColSize) * matrixSize;
    int* res = (int*)malloc((*returnSize) * sizeof(int));
    int top = 0, down = matrixSize - 1, left = 0, right = *matrixColSize - 1;
    int i = 0, k = 0;
    printf("size=%d\n",*returnSize);
    while(true){
        for(i = left; i <= right; i++){
            res[k++] = matrix[top][i];
        }
        top++;
        if(k >= *returnSize) break;
        for(i = top; i <= down; i++){
            res[k++] = matrix[i][right];
        }
        right--;
        if(k >= *returnSize) break;

        for(i = right; i >= left; i--){
            res[k++] = matrix[down][i];
        }
        down--;
        if(k >= *returnSize) break;

        for(i = down; i >= top; i--){
            res[k++] = matrix[i][left];
        }
        left++;
        if(k >= *returnSize) break;
        
    }
    return res;
}

