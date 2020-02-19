char * addBinary(char * a, char * b){
    //如果一个为空就直接返回另一个
    //先判断NULL
    if(a == NULL || *a == NULL)
        return b;
    if(b == NULL || *b == NULL)
        return a;
    //求出字符串长度并比较
    int len1 = strlen(a), len2 = strlen(b);
    int len = len1 > len2? len1 : len2; //取最长那个
    char* res = (char*)malloc(sizeof(char) * (len+2));// 分配res空间,+2一个给脑壳进位，一个给字符串结尾'\0'
    res[0] = '1', res[len+1] = '\0';
    int flag = 0,idx = len; //进位flag,idx是倒序加的下标
    while(len1 || len2 || idx){
        if(len1){
            flag += a[--len1] - '0';  
        }
        if(len2){
            flag += b[--len2] - '0';
        }
        res[idx--] = '0' + flag % 2;
        flag /= 2;
    }
    if(flag == 0){  //没有进位的情况
        char* tmp = (char*)malloc(sizeof(char) * (len + 1));
        memcpy(tmp, res+1, len+1);
        free(res);
        return tmp;
    }
    return res;
}

