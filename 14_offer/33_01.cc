class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder, 0, postorder.size()-1);
    }
private:
    bool dfs(vector<int>& postorder, int start, int end) {
        // 单个结点，必然valid
        if(start >= end) return true;
        int p = start;
        int rootVal = postorder[end];
        while(postorder[p] < rootVal) p++;
        // 左子树的end
        int leftEnd = p - 1;
        cout << leftEnd << endl;
        // 寻找右子树的end
        while(postorder[p] > rootVal) p++;
        return p == end && dfs(postorder, start, leftEnd) && dfs(postorder, leftEnd+1, end-1);
    }
};