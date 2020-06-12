class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 1);
        return maxLevel;
    }

    void dfs(TreeNode* root, int level) {
        if(!root) return;
        if(level > maxLevel) maxLevel = level;
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
private:
    int maxLevel;
};