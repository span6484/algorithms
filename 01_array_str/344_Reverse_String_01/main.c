void swap(char* a, char* b){
    char* c = (char*)malloc(sizeof(char));
    *c = *a;
    *a = *b;
    *b = *c;
}

void reverseString(char* s, int sSize){
    int i = 0, j = sSize - 1;
    while(i < j){
        swap(&s[i], &s[j]);
        i++;
        j--;
    }
    return s;
}

