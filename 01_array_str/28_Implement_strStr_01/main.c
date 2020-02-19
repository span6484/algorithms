int strStr(char * haystack, char * needle){
    if(strlen(needle) == 0) return 0;
    int needle_Len = strlen(needle), haystack_Len = strlen(haystack);
    int i = 0;
    if(needle_Len > haystack_Len) return -1;
    for(i = 0; i <= haystack_Len - needle_Len; i++){
        int j = 0;
        while(haystack[i+j] == needle[j]){
            if(j == needle_Len - 1) return i;
            j++;
        }
    }
    return -1;
}

