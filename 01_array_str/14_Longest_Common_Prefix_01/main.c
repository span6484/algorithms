
char * longestCommonPrefix(char ** strs, int strsSize){
    char* res = strs[0]; 
    if(strsSize == 0) return "";
    int i = 0,j = 0;
    for(i = 1; i < strsSize; i++){
        j = 0;
        while(strs[i][j] && res[j] && strs[i][j] == res[j]) j++;
        res[j] = '\0';
    }
    return res;
}

