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

## kmp

## 滑动窗口



https://github.com/youngyangyang04/leetcode-master