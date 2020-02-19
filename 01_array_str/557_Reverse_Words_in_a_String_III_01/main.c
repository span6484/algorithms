
void reverse(char* s, int start, int end){
    char tmp;
    while(start < end){
        tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        start++, end--;
    }
}

char * reverseWords(char * s){
    int start = 0, cur = 0;
    while(s[cur]){
        if(s[cur] == ' '){
            reverse(s, start, cur-1);
            start = ++cur;
        }else{
            cur++;
        }
    }
    reverse(s, start, cur-1);
    return s;
}

