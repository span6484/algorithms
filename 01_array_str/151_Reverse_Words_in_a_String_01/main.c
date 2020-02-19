void reverse(char*s, int start, int end){
    int i = start, j = end, tmp = 0;
    while(i < j){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++, j--;
    }
}
char * reverseWords(char * s){
    if(strlen(s) == 0 || !s) return "";  //一定要注意了

    //先吃前面的空格
    int cnt = 0, cur = 0, start = 0;
    while(s[cnt] == ' ') cnt++;
    while(s[cnt]!='\0'){
        if(s[cnt] == ' '){
            //表明他是第一个空格，直接reverse
            if(s[cnt-1] != ' '){
                reverse(s, start, cur-1);
            }
            //如果是空格，直接往后移
            if(s[cnt+1] == ' '){
                cnt++;
            }else if(s[cnt+1]!='\0'){  //如果是空格X
                s[cur++] = s[cnt++];   //添加空格
                start = cur;   //更新start
            }else{
                cnt++;   //如果是空格结束，往后移动就结束循环了
            }
        }else{
            s[cur++] = s[cnt++];  //X的话直接丢进去
        }
    }
    if(s[cnt-1] != ' '){     //如果最后一个是空格的话他就已经reverse了，如果不是我们这里还需要对最后一个进行reverse
        reverse(s, start, cur -1);
    }        
    s[cur] = 0;   //看了所有的情况之后都要给最后加结束符
    reverse(s, 0, cur -1);   //最后在进行一次总的reverse
    return s;   
}


