/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* tmp = (int*)malloc(sizeof(int) * (digitsSize + 1));
    tmp[0] = 1;
    int i = 0;
    for(i = digitsSize - 1; i >= 0; i--){
        if(digits[i] == 9){
            digits[i] = 0;
        }else{
            digits[i] += 1;  //直接不管后面了，后面肯定不会受到影响
            break;
        }
    }
    *returnSize = (digits[0] == 0? digitsSize + 1 : digitsSize);
    for(i = 1;i < digitsSize + 1; i++){
        tmp[i] = digits[i - 1];
    } 
    return digits[0] == 0? tmp : digits;
    
}
