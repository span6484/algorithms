## 模板汇总

## 分治

无

## 二叉树递归模板

```cpp
/* 二叉树遍历框架 */
void traverse(TreeNode root) {
    if(!root) return;
    // 前序遍历
    traverse(root->left)
    // 中序遍历
    traverse(root->right)
    // 后序遍历
}
```

## 总结二叉树迭代模板

- 前序遍历 

```cpp
void preorderTraversal(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        auto node = st.top(); st.pop();
        // do something here
        if(node->right != NULL) st.push(node->right);
        if(node->left != NULL) st.push(node->left);
    }
}
```

- 中序遍历 

```cpp
void inorderTraversal(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> st;
    while(root || !st.empty()) {
        while(root) {
            st.push(root);
            root = root->left;
        } 
        root = st.top(); st.pop();      
        // do something here
        root = root->right;
    }
    return res;
}
```

- 后序遍历 

```cpp

// 我们什么时候才能访问节点。有如下两种情况：

// 当前经过节点是叶子节点。
// 当前经过节点的右子节点是上一次访问的节点。

void postorderTraversal(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> st;
    TreeNode* prev = nullptr;
    while(root || !st.empty()) {
        while(root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        if(!root->right || root->right == prev) {
            st.pop();
            // do something here
            prev = root;
            root = nullptr;
        } else {
            root = root->right;
        }
    }
}
```

## 归并排序

```cpp
template<typename T> 
void merge_sort(vector<T>& arr) {
    mergeHelper(arr, 0, arr.size()-1);
}


template<typename T> 
void mergeHelper(vector<T>& arr, int left, int right) {
    if(left >= right) return;  // 1个的时候
    int mid = left + (right-left)/2;
    mergeHelper(arr, left, mid);
    mergeHelper(arr, mid+1, right);
    merge(arr, left, mid, right);
}

template<typename T> 
void merge(vector<T>& arr, int left, int mid, int right) {
    vector<T> tmp(right-left);
    int i = left, j = mid+1, k = 0;
    while(i < mid && j < right) {
        if(arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    // 判断哪个数组还有剩余
    int start = i, end = mid;
    if(j < right) {
        start = j;
        end = right;
    }
    while(start < right) {
        tmp[k++] = arr[start++];
    }
    // tmp 拷贝回A[left...right]
    for(int i = 0; i < right-left; i++) {
        arr[left+i] = tmp[i];
    }
}

```

## 快速排序


```cpp
// 把最背后一个当pivot
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        qsortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
    void qsortHelper(vector<int>& nums, int left, int right) {
        if(left >= right) return;
        int pivot = partition(nums, left, right);
        qsortHelper(nums, left, pivot - 1);
        qsortHelper(nums, pivot+1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int midVal = nums[right];
        for(int i = left; i < right; i++) {
            if(nums[i] < midVal) {
                swap(nums[left++], nums[i]);
            }
        }
        swap(nums[left], nums[right]);
        return left;
    }  
};

```

```cpp
// 上述快排可能会超时，我们选择随机选pivot
// 每次选择之前都是rand一下就可

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        qsortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
    void qsortHelper(vector<int>& nums, int left, int right) {
        if(left >= right) return;
        int pivot = random_partition(nums, left, right);
        qsortHelper(nums, left, pivot - 1);
        qsortHelper(nums, pivot+1, right);
    }
    
    int random_partition(vector<int>& nums, int left, int right) {
        int random = rand() % (right - left + 1) + left;
        swap(nums[random], nums[right]);
        return partition(nums, left, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int midVal = nums[right];
        for(int i = left; i < right; i++) {
            if(nums[i] < midVal) {
                swap(nums[left++], nums[i]);
            }
        }
        swap(nums[left], nums[right]);
        return left;
    }  
};

```

## 堆排序

## 二分法


```cpp
// [l, r)
l  = lowerest 
r = highest + 1
while l < r:
    m = l+(r-l)/2
    // if f(m) : return m  // optional
    if cond(m)
        r = m
    else 
        l = m + 1
return l;

Time O(log(r-l) * (f(m) + cond( m)))

```

## kmp

```cpp
// O(M+N)
// o(M)
void build(const string& pat) {
    int m = pat.size();
    dp.resize(m);
    for (int i = 0; i < m; ++i){
        dp[i].resize(256);
    }
    dp[0][pat[0]] = 1;
    int x = 0;
    for(int i = 1; i < m; i++) {
        for(int ch = 0; ch < 256; ch++) {
            if(pat[i] == ch) 
                dp[i][ch] = i+1;
            else 
                dp[i][ch] = dp[x][ch];
        }
        x = dp[x][pat[i]];
    }
}

int search(string txt, string pat) {   
    if(!pat.size()) return 0;
    int m = pat.size();
    int n = txt.size();
    build(pat);
    int state = 0;
    for(int i = 0; i < n; i++) {
        state = dp[state][txt[i]];
        if(state == m) return i - m + 1;
    }
    return -1;
}
```

## 滑动窗口


```cpp
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

# DP

## 背包问题

### 01背包

最基本的背包问题就是 01 背包问题：一共有 N 件物品，第 i（i 从 1 开始）件物品的重量为 w[i]，价值为 v[i]。在总重量不超过背包承载上限 W 的情况下，能够装入背包的最大价值是多少？

如果是 01 背包，即数组中的元素不可重复使用，外循环遍历 arrs，内循环遍历 target，且内循环倒序:

```cpp
vector<bool> dp(sum + 1, false);
dp[0] = true;
for(auto num : nums) {
    for(int i = sum; i >= num; i--) {
        dp[i] = dp[i] || dp[i-num];
    }
}
```

```cpp
vector<int> dp(sum+1, 0);
dp[0] = 1;
for(auto & num : nums) {
    for(int i = sum; i >= num; i--) {
        dp[i] = dp[i] + dp[i-num];
    }
}
```

###  完全背包问题：

（1）如果是完全背包，即数组中的元素可重复使用并且不考虑元素之间顺序，arrs 放在外循环（保证 arrs 按顺序），target在内循环。且内循环正序。

（2）如果组合问题需考虑元素之间的顺序，需将 target 放在外循环，将 arrs 放在内循环，且内循环正序。

## 编辑距离


-------------------------------------------------------------


## 回溯

```cpp
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}

```

## 链表

1. fast and slow ptr 

略

## 堆

use **priority_queue**

```cpp
// 用法
priority_queue<int> lo;   // max heap

priority_queue<long, vector<long>, greater<long> > heap; // 这几个是小顶堆

```

## DFS 

## BFS

## LRU

### other trick 

## split实现

```cpp
vector<string> split(const string& s) {
    istringstream in(s);
    vector<string> vec;
    string tmp;
    while(getline(in, tmp, ' ')) {
        if(tmp.size()) vec.push_back(tmp);
    }
    return vec;
}
```

https://github.com/youngyangyang04/leetcode-master
