
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

```
void slidwindow(vector<int> nums)
{
    int left = 0, right = 0;
    while(right < nums.size())
    {
        ...//扩大右边界并更新窗口状态
        right++;
        while(需要收缩)//窗口到达什么状态需要收缩
        {
            ...//缩小左边界并更新窗口状态
            left++;
        }
    }
}

```

## 3. Longest Substring Without Repeating Characters 



## 76. Minimum Window Substring

模板

o(n)

o(1)

## 567. Permutation in String

模板

o(n)

o(1)


## 438. Find All Anagrams in a String


模板

o(n)

o(1)



30 - Substring with Concatenation of All Words

239 - Sliding Window Maximum
424 - Longest Repeating Character Replacement
438
904 - Fruit into Baskets
930 
992
1004
1234
1248
