int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0) {
        *returnSize=0;
        return NULL;
    }
    *returnSize = matrixSize * (*matrixColSize);
    int* res = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0, j = 0, k = 0;

    for(k = 0; k < *returnSize; k++){
        res[k] = matrix[i][j];
        printf("i=%d,j=%d\n",i,j);
        if((i+j)%2){ //奇数
            if(i == matrixSize - 1){    //在最后一行，往右
                j += 1;
            }else if(j == 0){  //在第一列，往下
                i += 1;
            }else{  //左下
                i += 1;
                j -= 1;
            }
        }else{    //偶数
            if(j == *matrixColSize - 1){ //在最后一列,往下
                 i += 1;
             }else if(i == 0){  //在第一行，往右
                 j += 1;
             }else{   //右上
                 i -= 1;
                 j += 1;
             }
        }
    }
    return res;   
}
