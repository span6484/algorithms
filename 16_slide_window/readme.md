
## 模板

For most substring problem, we are given a string and need to find a substring of it which satisfy some restrictions. A general way is to use a hashmap assisted with two pointers.



```cpp
int findSubstring(string s){
    vector<int> map(128,0);
    int counter; // check whether the substring is valid
    int begin=0, end=0; //two pointers, one point to tail and one  head
    int len; //the length of substring
    int head = 0;   // 寻找substring需要找个记录

    for() { /* initialize the hash map here */ }

    while(end<s.size()){
        if(map[s[end]] ? ) {  // 看规则
             /* modify counter here */
        }
        map[s[end]]--;  // 看规则
        end++;

        while(/* counter condition */){ 
            1. /* update len and head here if finding minimum*/
                    
            if(map[s[begin]] ?){ 
                /*modify counter here*/ 
            }
            //increase begin to make it invalid/valid again
            map[s[start]]++;
            start++;
        } 
        2. /* update len and head here if finding minimum*/
    }
    return len == ? "" : s.substr(head, len);
  }

```

One thing needs to be mentioned is that when asked to find maximum substring, we should update maximum after the inner while loop to guarantee that the substring is valid. On the other hand, when asked to find minimum substring, we should update minimum inside the inner while loop.


## 3. Longest Substring Without Repeating Characters 

## 