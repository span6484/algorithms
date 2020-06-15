class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // contruct unordered_map
        for(int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        TreeNode* root = myBuild(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size());
        return root;
    }
    
    TreeNode* myBuild(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
        if(pre_left > pre_right) return nullptr;
        int pre_root_val = preorder[pre_left];
        int in_root = map[pre_root_val];
        int left_len = in_root - in_left;
        TreeNode* root = new TreeNode(pre_root_val);
        root->left = myBuild(preorder, inorder, pre_left+1, pre_left + left_len, in_left, in_root - 1);
        root->right = myBuild(preorder, inorder, pre_left + left_len + 1, pre_right, in_root + 1, in_right);
        return root;
    }
private:
    unordered_map<int, int> map;
};