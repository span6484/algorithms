class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(!inorder.size()) return nullptr;
        int len = inorder.size();
        cout << len << endl;
        for(int i = 0; i < len; i++) {
            m[inorder[i]] = i;
        }
        TreeNode* root = build(inorder, postorder, 0, len-1, 0, len-1);
        return root;
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int in_left, int in_right, int post_left, int post_right) {
        if(in_left > in_right) return nullptr;
        int rootVal = postorder[post_right];
        int in_root = m[rootVal];
        int len = in_root - in_left;
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(inorder, postorder, in_left, in_root-1, post_left, post_left + len - 1);
        root->right = build(inorder, postorder, in_root+1, in_right, post_left+len, post_right-1);
        return root;
    }
    
private:
    unordered_map<int, int> m;
};